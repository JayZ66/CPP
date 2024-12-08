
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

std::vector<int>	mergeInsertSort(const std::vector<int>& vectorArray) {

	if (vectorArray.size() < 2) // Si le vecteur est vide ou de taille 1, il est déjà trié.
		throw VectorException("Error: vectorArray does not contain enough elements");
	
	size_t	pivot = vectorArray.size() / 2;

	std::vector<int> firstHalf(vectorArray.begin(), vectorArray.begin() + pivot);
	/*
	- Utiliser le constructeur du std::vector avec la plage d’itérateurs.
	OU
	- Déclarer d’abord les vecteurs, puis appeler .assign.
	*/
	std::vector<int> secondHalf(vectorArray.begin() + pivot, vectorArray.end());

	// Pas besoin de check la size car si une sous-partie est de taille 1 ou vide, elle est déjà triée par définition, et la récursivité le gère naturellement.
	firstHalf = mergeInsertSort(firstHalf);
	secondHalf = mergeInsertSort(secondHalf);

	return mergeHalves(firstHalf, secondHalf);
}
// No returning a ref. because i'm using local objects only.

/*
Sending const ref in this function because our goal here is to combine 2 sorted vectors to return only one sorted !
So our half vectors are just used as data sources.
Conclusion : 
	- Passer par valeur : mauvais choix car cela entraînerait une copie inutile à chaque appel.
	- Passer par ref. constante : idéal car on ne modifie pas les vecteurs et on économise la copie.
*/
std::vector<int>	PmergeMe::mergeHalves(const std::vector<int>& firstHalf, const std::vector<int>& secondHalf) {

}