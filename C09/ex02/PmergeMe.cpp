
#include "PmergeMe.hpp"

/*
Ford-Johnson algo : 

Cet algo de tri combone 2 approches :
	- Tri par insertion (insertion sort) => Pour insérer les éléments triés au bon endroit dans une séquence
	- Tri par fusion (merge sort) => Pour fusionner efficacement des sous-séquences triées.

Steps : 
	1. Diviser la séquence en 2 groupes : deux sous-séquences de tailles égales ou presque égales (dépendant du nb total d'éléments)
	2. Tri des sous-séquences : Trier chaque sous-séquence individuellement. On peut utiliser un tri rapide comme std::sort.
	3. Fusion des sous-séquences triées : Fusionner les 2 sous-séquences triées en une seule séquence
		> Logique du tri par insertion : 
			- Prendre chaque élément de la seconde sous-séquence triée et insérez-le dans la position appropriée de la 1ère sous-séquence triée.
*/

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->_vector = other._vector;
		this->_deque = other;_deque;
	}
}

// Using assign() function that replace "old" values by the ones of the new vector that we sent + modifying vector size
void	PmergeMe::initializeContainers(const std::vector<int>& nbs) {
	_vector.assign(nbs.begin(), nbs.end());

	_deque.assign(nbs.begin(), nbs.end());
}

void	mergeInsertSort(const std::vector<int>& vectorArray) {

	if (vectorArray.size() < 2)
		throw VectorException("Error: vectorArray does not contain enough elements");
	
	std::vector<int>	firstHalf;
	std::vector<int>	secondHalf;
	for (size_t i = 0; i < vectorArray.size(); i++) {
		if (i % 2 == 0) {
			firstHalf.push_back(vectorArray.at(i));
		}
		else
			secondHalf.push_back(vectorArray.at(i));
	}
}