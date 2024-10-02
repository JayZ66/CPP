/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:07:55 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/02 18:07:59 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    mood;

    if (argc != 2) {
        std::cout << "One complain at a time please !" << std::endl;
        return 1;
    }
    std::string complain = argv[1];
    mood.complain(complain);
    return 0;
}









/*
POINTEURS VERS FONCTIONS MEMBRES : 

Pointeurs vers les Fonctions Membres

Un pointeur vers une fonction membre permet de référencer une
méthode d'une classe. Contrairement aux pointeurs vers des 
fonctions normales, les pointeurs vers des fonctions membres 
doivent tenir compte de l'objet auquel ils appartiennent.

1. Syntaxe de Déclaration

La syntaxe pour déclarer un pointeur vers une fonction membre 
est un peu différente de celle d'un pointeur vers une fonction 
classique. 

Voici la syntaxe générale :

RetType (ClassName::*pointerName)(ParamTypes);

    RetType : le type de retour de la fonction membre.
    ClassName : le nom de la classe contenant la fonction membre.
    pointerName : le nom du pointeur vers la fonction membre.
    ParamTypes : les types de paramètres de la fonction membre.


INTERET : 
Les pointeurs vers les fonctions membres sont utiles dans 
plusieurs scénarios, notamment :
1. Dynamisme dans le Choix des Méthodes

Ils permettent de choisir dynamiquement quelle méthode appeler 
sur un objet. Cela peut être particulièrement utile dans des 
situations où le comportement d'une application doit changer en 
fonction d'événements ou de données d'entrée.

2. Callback Functions

Les pointeurs vers les fonctions membres sont souvent utilisés 
comme mécanisme de callback. C’est particulièrement courant dans 
les frameworks d’interface graphique (GUI) et les systèmes 
d’événements, où tu veux exécuter une méthode d’une classe en 
réponse à un événement (comme un clic de souris).

3. Interfaces et Classes Abstraites

Les pointeurs vers les fonctions membres peuvent également être 
utilisés dans le contexte de classes abstraites et d'interfaces, 
permettant aux classes dérivées de spécifier comment elles 
doivent répondre à certaines méthodes.

Conclusion

Les pointeurs vers les fonctions membres sont un outil puissant 
pour gérer des comportements dynamiques et des événements dans 
tes programmes C++. Ils te permettent d'écrire un code plus 
flexible et adaptable, en te donnant la possibilité de choisir 
quelle méthode appeler à l'exécution.
*/