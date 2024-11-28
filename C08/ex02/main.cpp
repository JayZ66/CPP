
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
	//[...]
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

	std::cout << std::endl;
	std::cout << "TEST WITH ARRAY ! " << std::endl;

	std::vector<int>	vector;
	vector.push_back(5);
	vector.push_back(17);
	std::cout << "Vector last element added : " << vector.back() << std::endl; // Will return the last element of the container (as top())
	vector.erase(vector.end());
	std::cout << "Vector size: " << vector.size() << std::endl;
	vector.push_back(3);
	vector.push_back(5);
	vector.push_back(737);
	//[...]
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
	// std::stack<int> s(mstack);

	return 0;
}