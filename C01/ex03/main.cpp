/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:56:20 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 18:00:53 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "HumanA.hpp"
#include "Weapon.hpp"

// A reference NULL is not possible.

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}

/*
La différence entre HumanA et HumanB réside dans la façon dont chaque 
classe gère la possession d’une arme.

- HumanA
Doit toujours avoir une arme :
Dans le cas de HumanA, tu as décidé que chaque instance de HumanA doit
avoir une arme. Cela signifie que, lors de la création d’un objet HumanA,
tu dois obligatoirement lui fournir une référence à un objet Weapon.
C'est pourquoi tu utilises une référence dans le constructeur.
Cela garantit que HumanA est toujours armé, ce qui est essentiel pour
le comportement défini de cette classe (l’attaque doit toujours utiliser une arme).

- HumanB
Peut ne pas avoir d'arme :
Pour HumanB, la situation est différente. HumanB peut exister sans arme initialement,
ce qui signifie que tu ne peux pas obliger l’utilisateur de la classe à fournir
une arme au moment de la construction de l'objet. Au lieu de cela, HumanB peut
recevoir une arme plus tard via une méthode (comme setWeapon()). 
Cela donne plus de flexibilité, car un HumanB peut être créé sans arme et en obtenir
une plus tard, selon les besoins.

- Résumé
Référence dans HumanA : Assure que HumanA est toujours armé dès sa création.
Non nécessaire dans HumanB : Permet à HumanB d'être créé sans arme, et l’arme peut
être ajoutée ultérieurement.
*/