
#pragma once

#include <iostream>

template <typename T>
T swap(T& a, T& b) { // In order to change real/original values. (to check)
    T temp = a;
    a = b;
    b = temp;
}
// T here will mean void (nothing to return)

T min(T a, T b) { // No need here to use ref. no or need to return original value ?

}

T max(T a, T b) {

}