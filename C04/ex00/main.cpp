
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog(); // Pointeur vers un objet de type Dog
    const Animal* i = new Cat(); // Pointeur vers un objet de type Cat
    std::cout << "Type of j pointer is " << j->getType() << " " << std::endl;
    std::cout << "Type of i pointer is " << i->getType() << " " << std::endl;
    i->makeSound(); // Affiche "Meow" car i pointe vers un Cat
    j->makeSound();
    meta->makeSound();
    

    delete j;
    delete i;
    delete meta;

    std::cout << " ---------------- WRONG ANIMAL & WRONG CAT TESTS ---------------- " << std::endl;
    const   WrongAnimal* wrongAnimal = new WrongAnimal();
    const   WrongAnimal* otherAnimal = new WrongCat();

    std::cout << "Type of basic is " << wrongAnimal->getType() << " " << std::endl;
    std::cout << "Type of otherAnimal is " << otherAnimal->getType() << " " << std::endl;
    wrongAnimal->makeSound();
    otherAnimal->makeSound();

    delete wrongAnimal;
    delete  otherAnimal;
    
    return 0;
}