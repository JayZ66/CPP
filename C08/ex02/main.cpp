
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack; // Comme le conteneur sous-jacent est protégé on ne peut pas y accéder depuis une instance de notre classe, il faut donc créer des méthodes dans notre classe !
	mstack.push(5);
	mstack.push(17);
	std::cout << "Mstack last element added: " << mstack.top() << std::endl;
	mstack.pop(); // Erase last element added
	std::cout << "Mstack size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "Mstack element: " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "Last element of s: " << s.top() << std::endl;

	std::cout << std::endl;
	std::cout << "TEST WITH REV ITERATOR" << std::endl;
	MutantStack<int>::revIterator	RevEnd = mstack.rend();
	MutantStack<int>::revIterator	RevBegin = mstack.rbegin();
	while (RevBegin != RevEnd) {
		std::cout << "ConstStack element: " << *RevBegin << std::endl;
		++RevBegin;
	}



	std::cout << std::endl;
	std::cout << "TEST WITH CONST MUTANT STACK" << std::endl;
	MutantStack<double>	tmpStack;
	tmpStack.push(6.6);
	tmpStack.push(7.7);
	tmpStack.push(8.8);
	tmpStack.push(9.9);
	tmpStack.push(10.10);

	const MutantStack<double>	constStack = tmpStack;
	std::cout << "constStack size: " << constStack.size() << std::endl;
	 MutantStack<double>::const_iterator	constEnd = constStack.end();
	for (MutantStack<double>::const_iterator	constBegin = constStack.begin(); constBegin != constEnd; constBegin++) {
		std::cout << "constStack value: " << *constBegin << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST WITH CONST REV ITERATOR" << std::endl;
	MutantStack<double>::const_revIterator	constRevEnd = constStack.rend();
	MutantStack<double>::const_revIterator	constRevBegin = constStack.rbegin();
	while (constRevBegin != constRevEnd) {
		std::cout << "ConstStack element: " << *constRevBegin << std::endl;
		++constRevBegin;
	}




	std::cout << std::endl;
	std::cout << "TEST WITH ARRAY." << std::endl;

	std::vector<int>	vector;
	vector.push_back(5);
	vector.push_back(17);
	std::cout << "Vector last element added : " << vector.back() << std::endl; // Will return the last element of the container (as top())
	vector.erase(vector.end() - 1); // End is pointed just after the last element.
	std::cout << "Vector size: " << vector.size() << std::endl;
	vector.push_back(3);
	vector.push_back(5);
	vector.push_back(737);
	vector.push_back(0);
	std::vector<int>::iterator itVector = vector.begin();
	std::vector<int>::iterator iteVector = vector.end();
	++itVector;
	--itVector;
	while (itVector != iteVector)
	{
		std::cout << "vector value: " << *itVector << std::endl;
		++itVector;
	}

	std::cout << std::endl;
	std::cout << "REV TEST" << std::endl;
	std::vector<int>::reverse_iterator revend = vector.rend();
	std::vector<int>::reverse_iterator revbegin = vector.rbegin();
	while (revbegin != revend) {
		std::cout << "ConstStack element: " << *revbegin << std::endl;
		++revbegin;
	}

	std::cout << std::endl;
	std::cout << "COPY TEST" << std::endl;
	std::vector<int> copy;
	copy.insert(copy.begin(), vector.begin(), vector.end());

	std::vector<int>::iterator	iteratorBegin = copy.begin();
	std::vector<int>::iterator	iteratorEnd = copy.end();
	std::cout << "Copy last element: " << *iteratorBegin << std::endl;
	while (iteratorBegin != iteratorEnd) {
		std::cout << "copy value: " << *iteratorBegin << std::endl;
		++iteratorBegin;
	}

	return 0;
}