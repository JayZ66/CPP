
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // const Animal* meta = new Animal();
    const Animal* j = new Dog(); // Pointeur vers un objet de type Dog
    const Animal* i = new Cat(); // Pointeur vers un objet de type Cat
    std::cout << "Type of j pointer is " << j->getType() << " " << std::endl;
    std::cout << "Type of i pointer is " << i->getType() << " " << std::endl;
    i->makeSound(); // Affiche "Meow" car i pointe vers un Cat
    j->makeSound();
    // meta->makeSound();
    

    delete j;
    delete i;
    // delete meta;

    return 0;
}
// Check if the Brain() of each Cat or Dog is well deleted + if we have the Brain constructor mess.