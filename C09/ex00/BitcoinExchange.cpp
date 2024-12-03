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
		isValidDate(date); // try !!
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
	if (month == 2 && isLeapYear(year)) {
		if (day > 29)
			throw DateException("Date format is wrong - Invalid day for February in a leap year");
		else if (day > daysNbInMonth[month - 1])
			throw DateException("Date format is wrong - Invalid day for the given month");
	}

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
*/, 
, ,