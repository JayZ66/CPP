#include "Span.hpp"

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

int main()
{
	srand(time(NULL));

	Span	large(1000);
	std::vector<int>	largeArray;

	for (size_t i = 0; i < 1000; i++) {
		int value = rand();
		large.getIntArray().at(i) = value;
		std::cout << "Array[" << i << "] value: " << large.getIntArray().at(i) << std::endl;
	}

	return 0;
}