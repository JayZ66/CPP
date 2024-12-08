
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
		std::vector<int>	_vector;
		std::deque<int>		_deque;

	public:

	PmergeMe();
	PmergeMe(const PmergeMe& other);
	~PmergeMe();

	PmergeMe& operator=(const PmergeMe& other);

	void	initializeContainers(const std::vector<int>& nbs);
	std::vector<int>	mergeInsertSort(const std::vector<int>& vectorArray);
	std::vector<int>	mergeHalves(const std::vector<int>& firstHalf, const std::vector<int>& secondHalf);

	class VectorException : public std::exception {
		private:
			std::string	_message;

		public:
			VectorException(const std::string& message) : _message(message) {}
			virtual ~VectorException() throw() {}
			virtual const char* what() const throw() {
				return _message.c_str();
			}

	}

};