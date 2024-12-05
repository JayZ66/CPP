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
void    BitcoinExchange:: loadExchangeRates(const std::string& filePath) {

	std::ifstream   file(filePath.c_str()); // File en lecture
	std::string		line;

	if (!file.is_open()) {
		// std::cerr << "Error - Cannot open file at path: " << filePath << std::endl;
		throw FileException("Error - Cannot open file at path: " + filePath); // Throw an exception ??
	}
	std::getline(file, line); // Pour sauter la 1ère ligne > En-tête fichier
	while (getline(file, line)) {
		std::stringstream cut(line);
		std::string	date;
		std::string	strRate;

		if (!getline(cut, date, ',')) //Extraire jusqu'à la première virgule.
			continue ;
		// CHECK DATE FORMAT
		isValidDate(date); // try !! EXCEPTION REMONTE NATURELLEMENT AU PREMIER TRY RENCONTRE (casse toute l'execution)
		
		std::getline(cut, strRate); // Extraire le taux.
		if (strRate.empty()){ // Throw exception
			std::cerr << "Bitcoin rate is empty !" << std::endl;
			continue;
		}
		try {
			float	rate = std::strtof(strRate.c_str(), NULL);
			exchangeRates[date] = rate;
		}
		catch (const std::exception& e) {
			throw FileException("Error - Conversion failed");
		}
	}

	file.close();
}

bool	BitcoinExchange::isFloat(const std::string& price) const {
	char* end;
	std::strtof(price.c_str(), &end);
	return (end != price.c_str());
}

bool	BitcoinExchange::isNumeric(const std::string str) const {

	for (size_t i = 0; i < str.length(); i++) {
		
		if (!isFloat(str) && !std::isdigit(str[i]))
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
bool	BitcoinExchange::isLeapYear(int year) const {

	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void	BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10)
		throw DateException("Length not good");
	if (date[4] != '-' || date[7] != '-')
		throw DateException("Date format not good");

	if (!isNumeric(date.substr(0, 4)) || !isNumeric(date.substr(5, 2)) || !isNumeric(date.substr(8, 2)))
		throw DateException("Date format not good - Non numeric data");
	int	year = std::strtol(date.substr(0, 4).c_str(), NULL, 10);
	int	month = std::strtol(date.substr(5, 2).c_str(), NULL, 10);
	int	day = std::strtol(date.substr(8, 2).c_str(), NULL, 10);
	
	if (year < 2009)
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

/*
To find the the bitcoint price for the closest previous date in std::map for a given date (if this given date is not found)
=> Si la date utilisée en entrée n'existe pas dans la BDD, alors on utilise la date la plus proche dans la BDD.
*/
float	BitcoinExchange::findRateForClosestDate(const std::string& date) const {

	std::map<std::string, float>::const_iterator	it = exchangeRates.lower_bound(date); // return un it. vers le 1er élément dont la clé n'est pas inférieur à date.
	if (it == exchangeRates.begin() && it->first != date)
		throw DateException("No earlier date found for: " + date);
	if (it == exchangeRates.end() || it->first != date)
		--it;
	return it->second;
 }

void	BitcoinExchange::manageInputFile(const std::string& filePath) {

	std::ifstream	file(filePath.c_str());

	if (!file.is_open()) {
		throw FileException("Error - Could not open file");
	}

	std::string	line;
	std::getline(file, line);
	while (getline(file, line)) {
		std::stringstream	ss(line);
		std::string date;
		std::string	strRate;

		if (!std::getline(ss, date, '|') || !std::getline(ss, strRate)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
	// Supp. les espaces inutiles (avant et après la date et la valeur)
		date.erase(0, date.find_first_not_of(" \t\n\r"));
		date.erase(date.find_last_not_of(" \t\n\r") + 1);
		strRate.erase(0, strRate.find_first_not_of(" \t\n\r"));
		strRate.erase(strRate.find_last_not_of(" \t\n\r") + 1);
		if (!isNumeric(strRate)) {
			std::cerr << "Error: Bad input => " << strRate << std::endl;
			continue;
		}
	// Check si la date est valide (avec try)
		try {
			isValidDate(date);
		} catch (const std::exception& e) {
			std::cerr << "Error: Bad input => " << date << std::endl;
			continue;
		}
	// Convertir la valeur en nombre
		float	rateValue;
		try {
			rateValue = std::strtof(strRate.c_str(), NULL);
		} catch (const std::exception& e) {
			std::cerr << "Error: Invalid value => " << strRate << std::endl;
			continue;
		}
		// Check si la valeur est dans la plage valide (0 a 1000)
		if (rateValue < 0 || rateValue > 1000) {
			std::cerr << "Error: Value out of range => " << rateValue << std::endl;
			continue;
		}
		// Trouver le taux de change associé à la date
		float exchangeRate;
		try {
			exchangeRate = findRateForClosestDate(date);
		} catch (const std::exception& e) {
			std::cerr << "Error: Bad input => " << date << std::endl;
			continue;
		}
		// std::cerr << "EXCHANGE RATE: " << exchangeRate << std::endl;
		// std::cerr << "RATE VALUE: " << rateValue << std::endl;
		float	result = exchangeRate * rateValue;
		std::cout << date << " => " << rateValue << " = " << result << std::endl;
	}
	file.close();
}