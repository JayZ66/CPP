
#pragma once

#include <iostream>

// fonction template appelée iter qui applique une fonction à chaque élément d'un tableau, quel que soit le type 
// des éléments du tableau.

template <typename T> // Func représente le type de la fonction à appliquer.
/*
template <typename T, typename Func>
    - template : ce mot-clé indique qu’on crée un template. Il informe le compilateur que la fonction ou la classe qui suit 
    sera générique.
    - <typename T, typename Func> : ici, nous définissons deux paramètres de type :
        > T : représente le type d’éléments que le template va manipuler. Par exemple, T pourrait être un int, un float, 
        un std::string, etc.
        > Func : représente le type d’une fonction, c’est-à-dire un pointeur vers une fonction ou un objet fonctionnel 
        (functor) qui sera utilisé pour appliquer une opération sur chaque élément du tableau.
    => Can't use Func car le compilateur doit déduire ce qu'est Func lors de l'appel de la fonction, et ici il ne peut
    determiner que Func represente un type de fonction qui prend une ref. a un element T comme arg. (ici array[i])
*/

void    iter(T* array, int size, void(*function)(T&)) {

    for (int i = 0; i < size; i++) {
        function(array[i]);
    }
}

// To handle tests. ASK WHY PRECISELY
void    iter(T* array, int size, void(*function)(const T&)) {

    for (int i = 0; i < size; i++) {
        function(array[i]);
    }
}
