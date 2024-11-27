
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
#include <stack>

// Stack is a container that follows LIFO principle (Last in, First out)
// By default it is using a std::deque as an underlying container (sous-jacent) but we can use others like vector, list, etc.

// Key features : no index access + specify the container type when we declare std::stack

template <typename T>
class   MutantStack : public std::stack<T> {
    private:

    public:

    MutantStack();
    MutantStack(const MutantStack& other);
    ~MutantStack();

    MutantStack& operator=(const MutantStack& other);

    template <typename T>
    typename T::iterator begin();

    template <typename T>
    typename T::iteraot end();
};

/*
Principales méthodes de std::stack : 

*/