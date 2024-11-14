
#include "Array.hpp"

Array::Array : sizeArray(0), array(NULL) {}

Array::Array(unsigned int n) : array(new T[n]) {
    sizeArray = n
    for (int i = 0; i < n; i++) {
        array[i] = T(); // Check if it really gives the default value of the right type ! (int, string, double, ...)
    };
}

T*  Array::getArray() {
    return array;
}