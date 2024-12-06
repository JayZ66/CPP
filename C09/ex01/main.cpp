#include "RPN.hpp"


int main(int ac, char **av) {

	if (ac < 2) {
		std::cerr << "Error: add a file to calculate RPN expression" << std::endl;
		return 1;
	}
	std::string	expression = av[1];
	// Check input errors
	RPN	polishLine;
	try {
		polishLine.checkRpnExpression(expression);
		int	result;
		result = polishLine.prepareResult(expression);
		std::cout << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
