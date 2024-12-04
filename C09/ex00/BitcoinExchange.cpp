#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {} // Load CSV file data inside the container.

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->exchangeRates = other.exchangeRates;
	}
	return *this;
}

/*
std::stringstream : permet de manipuler une string comme si c'était un flux d'entrée/sortie.
- Extraire des morceaux de texte d'une chaîne comme on le fait depuis un fichier ou la console (std::cin)
- Ecrire dans une chaîne comme si c'était un flux de sortie (std::cout)

UTILE POUR : 
- Découper des chaînes basées sur des séparateurs
- Convertir des types (string vers int, float ou else)
- Formater des chaînes complexes
*/
void    BitcoinExchange::loadExchangeRates(const std::string& filePath) {

	std::ifstream   file(filePath); // File en lecture
	std::string		line;

	if (!file.is_open()) {
		// std::cerr << "Error - Cannot open file at path: " << filePath << std::endl;
		throw FileException("Error - Cannot open file at path: " + filePath); // Throw an exception ??
	}
	std::getline(file, line); // Pour sauter la 1ère ligne > En-tête fichier
	while (getline(file, line)) {
		std::stringstream	cut(line);
		std::string	date;
		std::string	strRate;

		if (!getline(cut, date, ',')) //Extraire jusqu'à la première virgule.
			continue ;
		// CHECK DATE FORMAT
		try {
			isValidDate(date); // try !!
		} catch (std::exception& e) {
			throw();
		}
		std::getline(cut, strRate); // Extraire le taux.
		if (strRate.empty()){ // Throw exception
			std::cerr << "Bitcoin rate is empty !" << std::endl;
			break;
		}
		try {
			float	rate = std::stof(strRate);
		}
		catch (const std::exception& e) {
			std::cerr << "Exception caught: rate conversion to float failed." << std::endl;
			continue;
		}
		exchangeRates[date] = rate;
	}

	file.close();
}

bool	isNumeric(const std::string str) const {

	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

/*
Une année est bissextile si elle est divisible par 4.
Exemples :
	- 2020 est divisible par 4, donc c'est une année bissextile.
	- 2023 n'est pas divisible par 4, donc ce n'est pas une année bissextile.

Cependant, les années divisibles par 100 ne sont pas bissextiles, sauf si elles sont également divisibles par 400.
Exemples :
	- 1900 est divisible par 100 mais pas par 400, donc ce n'est pas une année bissextile.
	- 2000 est divisible par 400, donc c'est une année bissextile.
*/
bool	isLeapYear(int year) const {

	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void	BitcoinExchange::isValidDate(const std::string& date) {

	if (date.length() != 10) {
		throw DateException("Date format is wrong - Length not good.");
	}
	if (date[4] != '-' || date[7] != '-')
		throw DateException("Date format is wrong - YYYY-MM-DD");
	
	std::stringstream	cut(date);
	std::string	strYear;
	std::string	strMonth;
	std::string	strDay;

	std::getline(cut, strYear, '-');
	std::getline(cut, strMonth, '-');
	std::getline(cut, strDay);

	// Check if digit
	if (!isNumeric(strYear) || !isNumeric(strMonth) || !isNumeric(strDay))
		throw DateException("Date format is wrong - Should be digits only");

	//Convert to int with strtol
	long year = std::strtol(strYear.c_str(), NULL, 10);
	if (year < 0)
		throw DateException("Date format is wrong - Year is not positive !");
	long month = std::strtol(strMonth, NULL, 10);
	if (month < 1 || month > 12)
		throw DateException("Date format is wrong - Month should be between 1 to 12"); 
	long day = std::strtol(strDay, NULL, 10);
	if (day < 1 || day > 31)
		throw DateException("Date format is wrong - Day should be between 1 to 31");
	
	const int	daysNbInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
		daysNbInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		throw DateException("Day not good in month.");

	return ;
}

/*
1. Découper la chaîne de date
Utilise un std::stringstream ou une autre méthode pour extraire l'année, le mois et le jour à partir de la chaîne de date.

Pseudo-code :
Vérifie que la chaîne contient exactement 10 caractères.
Assure-toi que les positions des tirets (-) sont correctes (4ème et 7ème caractères).
Extrait les parties de la chaîne et convertis-les en entiers (YYYY, MM, DD).
2. Vérifier les plages valides
Assure-toi que :

YYYY est une année valide (par exemple, 1900 ≤ YYYY ≤ 2100).
MM est un mois valide (1 ≤ MM ≤ 12).
DD est un jour valide dans le mois et l'année donnés (en tenant compte des années bissextiles).
3. Implémentation de la logique
Voici les étapes en détail :

Étape 1 : Vérification de la structure
Vérifie que la chaîne a une longueur de 10.
Vérifie que les 5ème et 8ème caractères sont des -.
Étape 2 : Extraire les parties de la date
Utilise substr() pour extraire YYYY, MM, et DD.
Convertis ces parties en entiers à l'aide de std::stoi().
Étape 3 : Valider la date
Vérifie les plages pour l'année, le mois et le jour.
Pour les jours, crée une liste des jours maximums pour chaque mois et gère les années bissextiles.
*/

void	BitcoinExchange::isValidDate(const std::string& date) const {

	if (date.length() != 10)
		throw DateException("Length not good");
	if (date[4] != '-' || date[7] != '-')
		throw DateException("Date format not good");

	// if (!isNumeric(date.substr(0, 4)) || !isNumeric(date.substr(5, 2)) || !isNumeric(date.substr(8, 2)))
	// 	throw DateException("Date format not good - Non numeric data");
	try {
		int	year = std::stoi(date.substr(0, 4), NULL, 10);
		int	month = std::stoi(date.substr(5, 2), NULL, 10);
		int	day = std::stoi(date.substr(8, 2), NULL, 10);
	
		if (year < 0)
		throw DateException("Wrong year");
	if (month < 1 || month > 12)
		throw DateException("Wrong month");
	if (day < 1 || day > 31)
		throw	DateException("Wrong day");

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		throw DateException("Day not good in month.");
	}
	catch (const std::invalid_argument&) { // Test if other errors are not going in this catch ??
		throw DateException("Date format error - Invalid numeric format");
	} catch (const std::out_of_range&) {
		throw DateException("Date format error - Value out of range");
	}
}

/*
To find the the bitcoint price for the closest previous date in std::map for a given date (if this given date is not found)
=> Si la date utilisée en entrée n'existe pas dans la BDD, alors on utilise la date la plus proche dans la BDD.
*/
 std::string	BitcoinExchange::findRateForClosestDate(const std::string& date) const {

	std::map<std::string, float>::const_iterator	it = exchangeRates.lower_bound(date); // return un it. vers le 1er élément dont la clé n'est pas inférieur à date.
	if (it == exchangeRates.begin() && it->first != date)
		throw DateException("No earlier date found for: " + date);
	if (it == exchangeRates.end() || it->first != date)
		--it;
	return it->second;
 }

    void    manageInputFile(const std::string& filePath) {

		std::ifstream	file(filePath);

		if (!file.is_open()) {
			throw FileException("Error - Could not open file");
		}

		std::string	line;
		std::getline(file, line);
		while (getline(file, line)) {
			std::stringstream	ss(line);
			std::string date;
			std::string	strRate;

			if (!std::getline(ss, date, '|') || !std::getline(ss, strRate))
				throw	FileException("Error - Bad input"); // Continue or not ?


		// Supp. les espaces inutiles (avant et après la date et la valeur)
			date.erase(0, date.find_first_not_of("\t"));
			strRate.erase(strRate.find_last_not_of("\t") + 1);

		// Check si la date est valide (avec try)
			try {
				isValidDate(date);
			} catch (const std::exception& e) {
				std::cerr << "Exception caught - Bad input => " << line << std::endl;
				continue;
			}

		// Convertir la valeur en nombre
			float	rateValue;
			try {
				rateValue = std::stof(strRate);
			} catch (const std::exception& e) {
				std::cerr << "Error - Invalid value => " << strRate << std::endl;
				continue;
			}

		// Check si la valeur est dans la plage valide (0 a 1000)
		if (rateValue < 1 || rateValue > 1000) {
			std::cerr << "Error - Value out of range => " << rateValue << std::endl;
			continue;
		}

		// Trouver le taux de change associé à la date
		try {
			float	exchangeRate = findClosestDate(date);
			float	result = exchangeRate * rateValue;
			std::cout << date << " => " << rateValue << " = " << result << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught - Bad input => " << line << std::endl;
		}
	}
	file.close();
}