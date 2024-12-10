
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

PmergeMe::PmergeMe() : _vectorChrono(0), _dequeChrono(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->_vector = other._vector;
		this->_deque = other._deque;
		this->_dequeChrono = other._dequeChrono;
		this->_vectorChrono = other._vectorChrono;
	}
	return *this;
}

// Using assign() function that replace "old" values by the ones of the new vector that we sent + modifying vector size
void	PmergeMe::initializeContainers(const std::vector<int>& nbs) {
	_vector.assign(nbs.begin(), nbs.end());

	_deque.assign(nbs.begin(), nbs.end());
}

/*
Sending const ref in this function because our goal here is to combine 2 sorted vectors to return only one sorted !
So our half vectors are just used as data sources.
Conclusion : 
	- Passer par valeur : mauvais choix car cela entraînerait une copie inutile à chaque appel.
	- Passer par ref. constante : idéal car on ne modifie pas les vecteurs et on économise la copie.
*/

// Goal here is to merge our sorted half vectors.
std::vector<int>	PmergeMe::mergeHalves(const std::vector<int>& firstHalf, const std::vector<int>& secondHalf) {

	std::vector<int>	sortedArray;

	std::vector<int>::iterator	itFirst = firstHalf.begin();
	std::vector<int>::iterator	itSecond = secondHalf.begin();

	while (itFirst != firstHalf.end() && itSecond != secondHalf.end()) {
		if (*itFirst < *itSecond) {
			sortedArray.push_back(*itFirst);
			++itFirst;
		}
		else {
			sortedArray.push_back(*itSecond);
			++itSecond;
		}
	}

	while (itFirst != firstHalf.end()) {
		sortedArray.push_back(*itFirst);
		++itFirst;
	}
	while (itSecond != secondHalf.end()) {
		sortedArray.push_back(*itSecond);
		++itSecond;
	}

	return sortedArray;
}

std::vector<int>	mergeInsertSort(const std::vector<int>& vectorArray) {

	if (vectorArray.size() < 2) // Si le vecteur est vide ou de taille 1, il est déjà trié.
		return vectorArray;
		// throw VectorException("Error: vectorArray does not contain enough elements");
	
	size_t	pivot = vectorArray.size() / 2;

	std::vector<int> firstHalf(vectorArray.begin(), vectorArray.begin() + pivot);
	/*
	- Utiliser le constructeur du std::vector avec la plage d’itérateurs.
	OU
	- Déclarer d’abord les vecteurs, puis appeler .assign.
	*/
	std::vector<int> secondHalf(vectorArray.begin() + pivot, vectorArray.end());

	// Pas besoin de check la size car si une sous-partie est de taille 1 ou vide, elle est déjà triée par définition, et la récursivité le gère naturellement.
	firstHalf = mergeInsertSort(firstHalf); // La récursivité va permettre de former des paquets de plus en plus petit.
	secondHalf = mergeInsertSort(secondHalf);

	return mergeHalves(firstHalf, secondHalf);
}
// No returning a ref. because i'm using local objects only.

void	PmergeMe::sortContainers() {
	if (_vector.size() <= 0 || _deque.size() <= 0)
		throw VectorException("Error : vector is empty");
	PmergeMe::timeSorting(std::vector<int>_vector, "vector");
	PmergeMe::timeSorting(_deque, "deque");
	// _vector = mergeInsertSort(_vector);
	// _deque = mergeInsertSortDeque(_deque);
}

std::deque<int>		PmergeMe::mergeInsertSortDeque(const std::deque<int>& dequeArray) {

	if (dequeArray.size() < 2)
		return dequeArray;
	size_t	pivot = dequeArray.size() / 2;
	std::deque<int>	firstHalf;
	std::deque<int>	secondHalf;

	firstHalf.assign(dequeArray.begin(), dequeArray.begin() + pivot);
	secondHalf.assign(dequeArray.begin() + pivot, dequeArray.end());

	firstHalf = mergeInsertSortDeque(firstHalf);
	secondHalf = mergeInsertSortDeque(secondHalf);

	return mergeSortedDeque(firstHalf, secondHalf);
}

std::deque<int>	PmergeMe::mergeSortedDeque(const std::deque<int>& firstHalf, const std::deque<int>& secondHalf) {

	std::deque<int>	sortedDeque;

	std::deque<int>::iterator	itFirst = firstHalf.begin();
	std::deque<int>::iterator	itSecond= secondHalf.begin();

	while (itFirst != firstHalf.end() && itSecond != secondHalf.end()) {
		if (*itFirst < *itSecond) {
			sortedDeque.push_back(*itFirst);
			++itFirst;
		}
		else {
			sortedDeque.push_back(*itSecond);
			++itSecond;
		}
	}

	while (itFirst != firstHalf.end()) {
		sortedDeque.push_back(*itFirst);
		++itFirst;
	}
	while (itSecond != secondHalf.end()) {
		sortedDeque.push_back(*itSecond);
		++itSecond;
	}
	
	// for (; itSecond < secondHalf.end(); ++itSecond) { // Pas le droit ??
	// 	sortedDeque.push_back(*itSecond);
	// }

	return sortedDeque;
}



