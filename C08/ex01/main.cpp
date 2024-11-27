#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) {
	*this = other;
}
    
Span::~Span() {}

Span& Span::operator=(const Span& other) {

	if (this != &other) {
		this->_maxSize = other._maxSize;
		this->array = other.array;
	}
	return *this;
}

void    Span::addNumber(int number) {
	if (intArray.size() >= this->_maxSize)
		throw addElementException("Cannot add more");
	intArray.push_back(number);
}

int    Span::shortestSpan() {

	if (intArray.size() < 2)
		throw shortestSpanException("Not enough elements in array");

	std::vector<int>	sorted = intArray;
	std::sort(sorted.begin(), sorted.end());
	int	diff;
	int minSpan= std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted.size(); i++) {
		diff = sorted.a(i + 1) - sorted.a(i);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int    Span::longestSpan() {
	if (intArray.size() < 2)
		throw longestSpanException("Not enough elements in array");

	int	min = *std::min_element(intArray.begin(), intArray.end());
	int	max = *std::max_element(intArray.begin(), intArray.end());

	int	maxSpan = max - min;
	return maxSpan;
}

template <typename T>
void	addNumbers(typename T::iterator begin, typename T::iterator end) {
	if (std::distance(begin, end) + intArray.size() >= _maxSize)
		throw addElementException("Cannot add to the container, no space left.");
	intArray.insert(intArray.end(), begin, end);
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

int	main () {
	srand(time(NULL));
	// 1. Test size 10000 + span
	Span	big(10000);
	std::vector<int>	bigArray;
	for (int i = 0; i < 10000; i++)
		bigArray.push_back(rand());
	try {
		std::cout << "Shortest span : " << big.shortestSpan() << std::endl;
		std::cout << "Longest span : " << big.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
		std::cout << "Caught exception: " << e.what() << std::endl;

	// 2. Test one nb + span
	Span	small(5);
	small.addNumber(3);
	try {
		std::cout << "Shortest span : " << small.shortestSpan() << std::endl;
		std::cout << "Longest span : " << small.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
		std::cout << "Caught exception: " << e.what() << std::endl;



	// 3. Test 2 nb + span

	// 4. Test addNb + span

	// 5. Test maxsize + span

	// 6. Test to init an array with addNb + addNbs (more) to fill int 2 times.
}



int main()
{
	srand(time(NULL));

	Span	large(10000);
	std::vector<int>	largeArray;

	for (size_t i = 0; i < 10000; i++) {
		largeArray.push_back(rand());
		std::cout << "Array[" << i << "] value: " << largeArray.at(i) << std::endl;
	}
	large.addNumbers<std::vector<int> >(largeArray.begin(), largeArray.end());
	try {
		std::cout << "Shortest span : " << large.shortestSpan() << std::endl;
		std::cout << "Longest span : " << large.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Try si un add nb dans le array
	std::cout << "Trying with one element in the array." << std::endl;
	Span	one(6);
	one.addNumber(1);
	try {
		std::cout << "Shortest span : " << one.shortestSpan() << std::endl;
	}	
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		one.addNumber(6);
		std::cout << "Longest span: " << one.longestSpan() << std::endl;
	}

	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		one.addNumber(5);
		one.addNumber(20);
		std::cout << "Longest span: " << one.longestSpan() << std::endl;
		std::cout << "Shortest span: " << one.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	Span	max(std::numeric_limits<unsigned int>::max());
	std::vector<int>	maxArray;
	for (int i = -5000; i < 10000; i++) {
		maxArray.push_back(i);
	}
	try {
		max.addNumbers<std::vector<int> >(maxArray.begin(), maxArray.end());
		std::cout << "Longest span: " << max.longestSpan() << std::endl;
		std::cout << "Shortest span: " << max.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}