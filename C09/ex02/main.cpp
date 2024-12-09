
#include "PmergeMe.hpp"

int	main(int ac, char **av) {

	if (ac < 2) {
		std::cerr << "Error: number of arguments" << std::endl;
		return 1;
	}
	std::vector<int>	vectorContainer;
	for (size_t i = 0; av[i]; i++) {
		size_t j = 0;
		while (av[i][j]) {
			if (!isdigit(av[i][j])) {
				std::cerr << "Error: this is not an integer element => " << av[i] << std::endl;
				return 1;
			}
			j++;
		}
		char*	endPtr;
		long	convert = std::strtol(av[i], &endPtr, 10);
		if (*endPtr == '\0') {
			if (convert < 0 || convert > INT_MAX) {
				std::cerr << "Error: digit is out of range" << std::endl;
				return 1;
			}
			vectorContainer.push_back(convert);
		}
	}

	PmergeMe	sorter;
	sorter.initializeContainers(vectorContainer);
	sorter.chronoSort(&PmergeMe::sortContainers, sorter._vector);

	return 0;
}