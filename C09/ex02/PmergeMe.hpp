
#pragma once

#include <stack>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <sstream>
#include <limits>
#include <limits.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <chrono>


// Goal : to sort a sequence of positive int. that has been given in args.
// We must use a variant to the sort algorithm which is called "merge-insert-sort" or Ford-Johnson
// And then sort elements with two different containers to compare process time.
class PmergeMe {
    private:

    public:

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();

    PmergeMe& operator=(const PmergeMe& other);

};