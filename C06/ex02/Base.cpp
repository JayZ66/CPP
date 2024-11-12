#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
    std::cout << "Base destructor has been called !" << std::endl;
}

// créer une instance aléatoire de A, B, ou C et la retourner sous forme de pointeur de type Base.
Base*   generate(void) {
    int randomNumber = rand() % 3;

    switch (randomNumber) {
        case 0:
            std::cout << "A object created !" << std::endl;
            return (new A);
            break; // Still needed but return should be enough.
        case 1:
            std::cout << "B object created !" << std::endl;
            return (new B);
            break;
        case 2:
            std::cout << "C object created !" << std::endl;
            return (new C);
            break;
        default:
            return NULL;
    }
}

/*
dynamic_cast permet de vérifier si le type réel de l’objet pointé correspond à un type cible, 
en retournant un pointeur non nul si le cast est réussi, ou nul sinon.
*/

// utilisera un pointeur de type Base* pour déterminer le type réel de l’objet pointé par p et de print le résultat.
void    identify(Base* p) { 

    if (dynamic_cast<A*>(p) != NULL) // Check why we don't need to declare our derived class object pointer !
        std::cout << "Object pointed by p is A !" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Object pointed by p is B !" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Object pointed by p is C !" << std::endl; // Why can't use *this here ??
    else
        std::cout << "P is not pointing an derived object from Base class.";
}

// faire la même chose mais avec une référence, sans convertir la référence en pointeur.
void    identify(Base& p) {

    try {
        A& aRef = dynamic_cast<A&>(p);
        (void) aRef;
        std::cout << "p is a reference to A derived class object !" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
        // std::cout << "Object is not of type A." << std::endl;
        try {
            B& bRef = dynamic_cast<B&>(p);
            (void) bRef;
            std::cout << "p is a reference to B derived class object !" << std::endl;
            return;
        }
        catch (std::exception& e)
        {
            // std::cout << "Object is not of type B." << std::endl;
            try  {
            C& cRef = dynamic_cast<C&>(p);
            (void) cRef;
            std::cout <<  "p is a reference to C derived class object !" << std::endl;
            return;
            }
            catch (std::exception& e) {
               std::cout << "p is not a reference to any derived class object !" << std::endl;
            }
        }
    }
}