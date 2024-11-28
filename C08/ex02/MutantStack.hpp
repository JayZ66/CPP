
#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <sstream>
#include <limits>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <stack>

// Stack is a container that follows LIFO principle (Last in, First out)
// By default it is using a std::deque as an underlying container (sous-jacent) but we can use others like vector, list, etc.

// Key features : no index access + specify the container type when we declare std::stack

template <typename T> // To contain any type of elements in the stack. > To specify when we create MutantStack object
class   MutantStack : public std::stack<T> {
    private:

    public:

    MutantStack() {} // Will call the std::stack default constructor
    MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {} // std::stack gère auto l'allocation & la gestion des éléments internes, il suffit donc d'init le conteneur du new objet en copiant celui de l'objet other.
    ~MutantStack() {}

    MutantStack<T>& operator=(const MutantStack<T>& other) {
        if (this != &other) {
            std::stack<T>::operator=(other); // Appelle l'opérateur d'assignation de std::stack to copy le contenu de other dans le container sous-jacent de l'objet actuel.
        }
        return *this;
    }

/*
container_type : 
    std::stack est un wrapper autour d'un conteneur sous-jacent, ce dernier est défini par le type container_type (type membre de std::stack).
    Si on ne précise rien, std::stack utilise donc std::deque sinon il faut spécifier container_type.
*/
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin() {
        return this->c.begin();
    }
    iterator end() {
        return this->c.end();
    }
    
    const_iterator begin() const {
        return this->c.begin();
    }
    const_iterator end() const {
        return this->c.end();
    }
};

/*
Principales méthodes de std::stack : 

*/

// Pour accéder au conteneur sous-jacent on utilise la notation this->c (c est un membre protégé de la classe std::stack)
// Cela permet de work avec le conteneur sous-jacent sans modifier le comportement de la pile.