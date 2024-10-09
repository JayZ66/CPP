
#include "Brain.hpp"

// No need to init the ideas tab ?
Brain::Brain( void ) {
    std::cout << "Default Brain constructor has been called !" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = "Default ideas";
}

Brain::Brain( const Brain& other ) {
    *this = other;
}

Brain& Brain::operator=( const Brain& other ) {
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor has been called !" << std::endl;
}
