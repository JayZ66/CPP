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

		std::getline(cut, date, ','); //Extraire jusqu'à la première virgule.
		// CHECK DATE FORMAT
		std::getline(cut, strRate); // Extraire le taux.
		if (strRate.empty()){
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

bool	BitcoinExchange::isValidDate(const std::string& date) {


}
