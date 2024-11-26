
#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <sstream>


// Can also use an existing exception : std::logic_error() => erreur de programmation dans le code, qui ne devrait pas se produire a l'execution.
class FindTargetNumberException : public std::exception {
    
    private:
        std::string _message;

    public:
    FindTargetNumberException(const std::string& message) : _message(message) {}
    virtual ~FindTargetNumberException() throw() {};
    virtual const char* what() const throw() {
        return _message.c_str(); // Return a pointer to a char array to be compatible with c function/type
    }
};

// Return : iterateur pointant vers l'element found or throw exception.
// pour un template T, l'itérateur associé est typename T::iterator. Add typename pour indiquer que iterator est un type (et non un membre ou une méthode).

template <typename T>
typename T::iterator   easyfind(T& intContainer, int target) {
    typename T::iterator it = std::find(intContainer.begin(), intContainer.end(), target); // Look for target nb from thr beginning to the end of the container.
    if (it != intContainer.end()) {
        // std::cout << "Target number " << target << " has been found." << std::endl;
        return (it);
    }

    else {
        std::ostringstream  convert;
        convert << target;
        std::string result = convert.str(); // Return the stream content under string representation
        throw FindTargetNumberException("Target number " + result + " not found !");
    }
}


/*
typename : typename T::iterator

En C++, lorsqu'un template est utilisé, le compilateur ne peut pas deviner si T::iterator est un type ou autre chose 
(comme une variable ou une fonction) avant d’avoir instancié le template.
Le mot-clé typename indique explicitement au compilateur que T::iterator est un type.

Pourquoi est-ce nécessaire ?
Sans typename, le compilateur pourrait confondre T::iterator avec un membre ou une méthode, ce qui provoquerait une erreur.

T::iterator :
    - T est le type passé en tant que paramètre template (par exemple, std::vector<int> ou std::list<int>).
    - T::iterator est le type de l'itérateur associé à T.
        > Si T est un std::vector<int>, alors T::iterator sera std::vector<int>::iterator.
        > Si T est un std::list<int>, alors T::iterator sera std::list<int>::iterator.

it :
C’est le nom de la variable. Ici, it est déclaré comme un itérateur sur le container T.
*/

/*
Preciser le type du retour et pas celui du parametre :

La raison fondamentale est que les paramètres des fonctions template sont des entrées connues au moment de l'appel, alors 
que le type de retour doit être déduit ou spécifié au moment de la compilation.

Déduction des types des paramètres :
Quand tu passes un argument (comme vectorArray), le compilateur peut inspecter son type. Il en déduit directement T et adapte 
la fonction template en conséquence.

Pas de déduction pour le type de retour :
Le type de retour ne peut pas être déduit indépendamment parce qu’il dépend de la déclaration de la fonction. Le compilateur 
doit être explicitement guidé, surtout dans les cas où le type de retour utilise une construction complexe comme T::iterator.


*/