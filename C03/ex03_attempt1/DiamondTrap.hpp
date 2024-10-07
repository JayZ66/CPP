



#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap
{
    private:
    std::string _name; // Nom propre a Diamond Trap.
    int         _energy;

    public:

    DiamondTrap( void );
    DiamondTrap( const std::string& _pname, int _pHitPoints, int _pEnergyPoints, int _pAttackDamage );
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
