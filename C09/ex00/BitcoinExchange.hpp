
#pragma once

#include <map>
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
#include <cstdlib>

class BitcoinExchange {
    private:
        std::map<std::string, float> exchangeRates; // Stocker les prix des bitcoin par date (string > struct. de date)

    public:
    BitcoinExchange(); // Load CSV file data inside the container.
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    BitcoinExchange& operator=(const BitcoinExchange& other);

    void    loadExchangeRates(const std::string& filePath);
    void    isValidDate(const std::string& date);

    class   FileException : public std::exception {
        private:
            std::string _message;
        public:
            FileException(const std::string& message) : _message(message) {}
            virtual ~FileException() throw() {}
            virtual const char* what() const throw() {
                return _message.c_str();
            }
    };

    class   DateException : public std::exception {
        private:
            std::string _message;
        public:
            DateException(const std::string& message) : _message(message) {}
            virtual ~DateException() throw() {}
            virtual const char* what() const throw() {
                return _message.c_str();
            }
    };

};