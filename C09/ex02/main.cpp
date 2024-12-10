
#include "PmergeMe.hpp"

int	main(int ac, char **av) {

	if (ac < 2) {
		std::cerr << "Error: number of arguments" << std::endl;
		return 1;
	}
	std::vector<int>	vectorContainer;
	for (size_t i = 1; i < ac; i++) {
		char*	endPtr;
		long	convert = std::strtol(av[i], &endPtr, 10);
		if (*endPtr != '\0' || convert < 0 || convert > INT_MAX) {
				std::cerr << "Error: invalid number: " << av[i] << std::endl;
				return 1;
		}
		vectorContainer.push_back(static_cast<int>convert);
	}

	PmergeMe	sorter;
	sorter.initializeContainers(vectorContainer);
	sorter.chronoSort(&PmergeMe::sortContainers, sorter._vector);

	return 0;
}