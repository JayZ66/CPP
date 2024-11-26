
#pragma once


#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <sstream>
#include <limits>
#include <time.h>
#include <ctime>
#include <cstdlib>

class Span {
    private:
        unsigned int    _maxSize;
        std::vector<int> intArray; // Le constructeur de vector est appele et init le vector a 0 comme c'est un conteneur dynamique

    public:

    Span();
    Span(unsigned int n);
    Span(const Span& other);
    ~Span();

    Span& operator=(const Span& other);

    void    addNumber(int number);
    int    shortestSpan(); // Return the shortest distance between two nb.
    int    longestSpan(); // Return the longest distance between two nb.

    std::vector<int>&    getIntArray();

class shortestSpanException : public std::exception {
    private:
        std::string _message;

    public:
        shortestSpanException(const std::string message) : _message(message) {}
        virtual ~shortestSpanException() throw () {}
        virtual const char* what() const throw() {
            return _message.c_str();
        }
};

class longestSpanException : public std::exception {
    private:
        std::string _message;

    public:
        longestSpanException(const std::string message) : _message(message) {}
        virtual ~longestSpanException() throw() {}
        virtual const char* what() const throw() {
            return _message.c_str();
        }
};

class addElementException : public std::exception {
    private:
        std::string _message;

    public:
        addElementException(const std::string message) : _message(message) {}
        virtual ~addElementException() throw() {}
        virtual const char* what() const throw() {
            return _message.c_str();
        }
};

template <typename T>
void	addNumbers(typename T::iterator begin, typename T::iterator end) {
	if (std::distance(begin, end) + intArray.size() > _maxSize) {
		throw addElementException("Cannot add to the container, no space left.");
	}
	intArray.insert(intArray.end(), begin, end);
}


};

