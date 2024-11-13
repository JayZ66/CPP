
#pragma once

#include <iostream>

template <typename T>
void swap(T& a, T& b) { // In order to change real/original values. (to check)
    T temp = a;
    a = b;
    b = temp;
}
// Can't put T if the function 

template <typename T> // Why should we put it before each function template ?
T min(T a, T b) { // No need here to use ref. no or need to return original value ?
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
T max(T a, T b) {
    if (a > b)
        return a;
    else
        return b;
}