
#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) {
    *this = other;
}

Span::~Span() {}

Span&   Span::operator=(const Span& other) {
    if (this != &other) {
        this->_maxSize = other._maxSize;
        this->intArray = other.intArray;
    }
    return *this;
}

void    Span::addNumber(int number) {
    if (intArray.size() >= this->_maxSize) // Check si l'array a reach la maxSize
        throw addElementException("Container is full, maxSize has been reached");
    else {
        intArray.push_back(number);
        std::cout << "Number " << number << " has been successfully added." << std::endl;
    }
    std::cout << std::endl;
}

int    Span::longestSpan() { // Return the longest distance between two nb.
    if (intArray.size() <= 1) {
        throw longestSpanException("Not enough elements to calculate span.");
    }
    int min = *std::min_element(intArray.begin(), intArray.end()); // Return a pointer to the min/max value of the container.
    int max = *std::max_element(intArray.begin(), intArray.end());

    int longestSpan = max - min;
    return longestSpan;
}

int    Span::shortestSpan(){ // Return the shortest distance between two nb.
    if (intArray.size() <= 1) {
        throw shortestSpanException("Not enough elements to calculate span.");
    }
    std::vector<int> sortedArray = intArray;
    std::sort(sortedArray.begin(), sortedArray.end());
    int diff;
    int minSpan = std::numeric_limits<int>::max(); // Init minSpan with the max int.
    for (size_t i = 0; i < sortedArray.size() - 1; i++) {
        diff = sortedArray.at(i+1) - sortedArray.at(i);
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

std::vector<int>    Span::getIntArray() {
    return intArray;
}
