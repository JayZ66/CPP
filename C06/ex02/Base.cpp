#include "Base.hpp"

// créer une instance aléatoire de A, B, ou C et la retourner sous forme de pointeur de type Base.
Base*   Base::generate(void) {
    if (rand % 2)
}

/*
dynamic_cast permet de vérifier si le type réel de l’objet pointé correspond à un type cible, 
en retournant un pointeur non nul si le cast est réussi, ou nul sinon.
*/

// utilisera un pointeur de type Base* pour déterminer le type réel de l’objet.
void    Base::identify(Base* p) { 

}

// faire la même chose mais avec une référence, sans convertir la référence en pointeur.
void    Base::identify(Base& p) {

}