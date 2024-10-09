
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    const   Animal* animals[10];
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < 10; i++) {
        animals[i]->makeSound(); // Check if we have the right sound depending on the object (Cat or Dog).
    }
    
    for (int i = 0; i < 10; i++) {
        delete animals[i];
    }

    return 0;
}
// Check if the Brain() of each Cat or Dog is well deleted + if we have the Brain constructor mess.