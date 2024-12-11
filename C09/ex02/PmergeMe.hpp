
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
#include <climits>
#include <sys/time.h>
#include <typeinfo>


// Goal : to sort a sequence of positive int. that has been given in args.
// We must use a variant to the sort algorithm which is called "merge-insert-sort" or Ford-Johnson
// And then sort elements with two different containers to compare process time.
class PmergeMe {
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		double				_vectorChrono;
		double				_dequeChrono;

	public:

	PmergeMe();
	PmergeMe(const PmergeMe& other);
	~PmergeMe();

	PmergeMe& operator=(const PmergeMe& other);

	void	initializeContainers(const std::vector<int>& nbs);
	std::vector<int>	mergeInsertSort(const std::vector<int>& vectorArray);
	std::vector<int>	mergeHalves(const std::vector<int>& firstHalf, const std::vector<int>& secondHalf);
	std::deque<int>		mergeInsertSortDeque(const std::deque<int>& dequeArray);
	std::deque<int>		mergeSortedDeque(const std::deque<int>& firstHalf, const std::deque<int>& secondHalf);
	void				sortContainers();
	void				printResult(const std::string containerName, const double finalTime) const;

	template <typename Container>
	void timeSorting(Container& container, const std::string& containerName) {
		Container containerCopy = container;

		clock_t start = clock();
		if (typeid(container) == typeid(std::vector<int>)) {
			std::vector<int> vectorCopy(containerCopy.begin(), containerCopy.end());
			vectorCopy = mergeInsertSort(vectorCopy);
			_vector = vectorCopy;
		} else if (typeid(container) == typeid(std::deque<int>)) {
			std::deque<int> dequeCopy(containerCopy.begin(), containerCopy.end());
			dequeCopy = mergeInsertSortDeque(dequeCopy);
			_deque = dequeCopy;
		} else {
			throw std::runtime_error("Unsupported container type");
		}
		clock_t end = clock();

		double finalTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // En microseconds
		printResult(containerName, finalTime);
	}

	// void	timeSorting(Container& container, const std::string& containerName) {
	// 	Container&	containerCopy = container;

	// 	clock_t start = clock();
	// 	if (typeid(container) == typeid(std::vector<int>)) {
	// 		containerCopy = mergeInsertSort(containerCopy);
	// 	}
	// 	else {
	// 		containerCopy = mergeInsertSortDeque(containerCopy);
	// 	}
	// 	clock_t	end = clock();

	// 	double	finalTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // En microseconds
	// 	std::cout << "Time taken to sort " << containerName << ": " << finalTime << " microseconds." << std::endl;
	// }

	class VectorException : public std::exception {
		private:
			std::string	_message;

		public:
			VectorException(const std::string& message) : _message(message) {}
			virtual ~VectorException() throw() {}
			virtual const char* what() const throw() {
				return _message.c_str();
			}

	};

	class DequeException : public std::exception {
		private:
			std::string	_message;

		public:
			DequeException(const std::string& message) : _message(message) {}
			virtual ~DequeException() throw() {}
			virtual const char* what() const throw() {
				return _message.c_str();
			}

	};

};