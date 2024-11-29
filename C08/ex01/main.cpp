#include "Span.hpp"

int	main () {

	std::cout << "SUBJECT TESTS" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "MY OWN TESTS" << std::endl;

	srand(time(NULL));
	// 1. Test size 15000 + span
	std::cout << "TEST WITH A SIZE OF 15000: " << std::endl;
	Span	big(15001);
	std::vector<int>	bigArray;
	for (int i = 0; i < 15000; i++)
		bigArray.push_back(rand());
	try {
		big.addNumbers<std::vector<int> >(bigArray.begin(), bigArray.end());
		std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
		std::cout << "Longest span: " << big.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// 2. Test one nb + span
	std::cout << "TEST WITH ONE NUMBER: " << std::endl;
	Span	small(5);
	try {
		small.addNumber(3);
		std::cout << "Shortest span: " << small.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// 3. Test 2 nb + span
	std::cout << "TEST WITH TWO NUMBERS: " << std::endl;
	try {
		small.addNumber(15);
		std::cout << "Longest span: " << small.longestSpan() << std::endl;
		std::cout << "Shortest span: " << small.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	// 4. Test addNb + span
	std::cout << "TEST WITH FOUR NUMBERS: " << std::endl;
	try {
		small.addNumber(150);
		small.addNumber(46);
		std::cout << "Shortest span: " << small.shortestSpan() << std::endl;
		std::cout << "Longest span: " << small.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// 5. Test maxsize + span
	std::cout << "TEST WITH NUMEROUS NUMBERS: " << std::endl;
	Span	maxArray(std::numeric_limits<int>::max());
	std::deque<int>	dequeArray;
	for (size_t i = -15000; i < 30000; i++) {
		dequeArray.push_back(rand());
	}
	try {
		maxArray.addNumbers<std::deque<int> >(dequeArray.begin(), dequeArray.end());
		std::cout << "Shortest span: " << maxArray.shortestSpan() << std::endl;
		std::cout << "Longest span: " << maxArray.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caugth: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// 6. Test to init an array with addNb + addNbs (more) to fill int 2 times.
	std::cout << "TEST WITH COPY CONSTRUCTOR & ADD MULTIPLE NUMBERS: " << std::endl;
	Span	copy(small);
	// Span	copy(maxArray);
	try {
		copy.addNumber(6);
		copy.addNumber(8);
		std::cout << "Shortest span: " << copy.shortestSpan() << std::endl;
		std::cout << "Longest span: " << copy.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::vector<int>	copyArray;
	for (int i = 0; i < 50; i++) {
		copyArray.push_back(rand());
	}
	try {
		copy.addNumbers<std::vector<int> >(copyArray.begin(), copyArray.end());
		std::cout << "Shortest span: " << copy.shortestSpan() << std::endl;
		std::cout << "Longest span: " << copy.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caugth: " << e.what() << std::endl;
	}

}
