

#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap
{
    private:
    std::string _name; // Nom propre a Diamond Trap.

    public:

    DiamondTrap( void );
    DiamondTrap( const std::string& _pname );
    DiamondTrap( const DiamondTrap& other);
    DiamondTrap& operator=( const DiamondTrap& other);
    ~DiamondTrap( void );

    void    whoAmI();
    void    attack(const std::string& target);
};

/*
std::string& _pname / std::string& target :
Pas de copie : Le paramètre _pname ne créera pas une copie de la chaîne, ce qui est plus 
efficace. Cela devient particulièrement pertinent lorsque tu passes de grandes chaînes ou des 
objets complexes.
*/

/*
-------------- EXPLICATIONS HERITAGE DIAMANT --------------

Problème de l'héritage en diamant :
    L'héritage en diamant survient lorsqu'une classe dérivée (dans ton cas, DiamondTrap) hérite 
    de deux classes (ScavTrap et FragTrap) qui elles-mêmes héritent d'une même classe de base 
    (ici, ClapTrap). Cela crée un "chemin" multiple vers les membres et les méthodes de ClapTrap, 
    causant des ambiguïtés potentielles.

    Voici ce qui se passe sans héritage virtuel :

        1. ClapTrap est une classe de base pour ScavTrap et FragTrap.
        2. DiamondTrap hérite à la fois de ScavTrap et de FragTrap.
        3. Lorsqu'un objet de type DiamondTrap est créé, il y a deux instances distinctes de 
        ClapTrap :
            - Une associée à ScavTrap.
            - Une associée à FragTrap.

    Ainsi, lorsqu'un objet DiamondTrap est construit, ClapTrap est en réalité construit deux 
    fois (via ScavTrap et FragTrap). Cela entraîne une ambiguïté concernant les attributs 
    hérités de ClapTrap, comme _hitPoints, _energyPoints et _attackDamage, car ils sont 
    "dupliqués" dans deux chemins d'héritage.

    
    Ordre de construction et d'initialisation
    Lorsque tu construis un objet DiamondTrap, voici l'ordre dans lequel les constructeurs sont 
    appelés :

        1. ClapTrap (via ScavTrap).
        2. ClapTrap (via FragTrap).
        3. ScavTrap.
        4. FragTrap.
        5. DiamondTrap.
    Ce double appel au constructeur de ClapTrap signifie que, même si tu initialises certains 
    attributs via ScavTrap, l'appel ultérieur au constructeur de FragTrap peut écraser ces 
    valeurs, car les deux classes ont leur propre copie des attributs hérités de ClapTrap.

    
    Pourquoi l'héritage virtuel résout ce problème :
    L'héritage non-virtuel fait que chaque branche de l'arbre d'héritage (ScavTrap et FragTrap) 
    a sa propre copie des attributs hérités de ClapTrap, ce qui mène à la duplication. C'est ce 
    qui cause ton problème : les valeurs des attributs de FragTrap écrasent celles de ScavTrap 
    parce que la copie de FragTrap est créée après celle de ScavTrap.

    L'héritage virtuel, quant à lui, garantit qu'il n'y a qu'une seule instance de la classe de 
    base commune (ici, ClapTrap), même si elle est héritée par plusieurs classes intermédiaires. 
    Cela évite la duplication des attributs de ClapTrap. Avec l'héritage virtuel, ClapTrap 
    serait construit une seule fois, et DiamondTrap n'aurait qu'une seule version des attributs 
    de ClapTrap, partagée entre ScavTrap et FragTrap.

En résumé
    - Sans héritage virtuel, ClapTrap est instancié deux fois : une pour ScavTrap et une pour 
    FragTrap. Cela crée des copies redondantes des attributs de ClapTrap, et l'ordre de 
    construction fait que les valeurs héritées de FragTrap peuvent écraser celles de ScavTrap.
    - Avec héritage virtuel, il n'y a qu'une seule instance partagée de ClapTrap, évitant ainsi 
    tout conflit ou ambiguïté dans les attributs hérités.

Conclusion
Même avec l'héritage virtuel, le problème se pose toujours parce que les constructeurs de 
ScavTrap et FragTrap sont appelés après le constructeur de ClapTrap, et ils peuvent écraser les 
mêmes attributs hérités. La solution consiste à reprendre le contrôle des valeurs des attributs 
dans le constructeur de DiamondTrap ou à mieux organiser les constructeurs des classes 
intermédiaires pour éviter les conflits.

*/
