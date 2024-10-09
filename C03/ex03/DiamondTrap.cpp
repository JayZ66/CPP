
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap() {}

DiamondTrap::DiamondTrap( const DiamondTrap& other)
{
    *this = other;
}

DiamondTrap&    DiamondTrap::operator=( const DiamondTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->_name = other._name;
    }
    return *this;
}

DiamondTrap::DiamondTrap( const std::string& _pname ) : ClapTrap(_pname + "_clap_name"), ScavTrap(_pname), FragTrap(_pname), _name(_pname)
{
    _hitPoints = FragTrap::_hitPoints;
    _attackDamage = FragTrap::_attackDamage;
    _energyPoints = ScavTrap::getEnergyP();
    std::cout << "Default constructor called, DiamondTrap name is " << _name << ", it has " << _hitPoints << " hit points, " << _energyPoints << " energy points and " << _attackDamage << " attack damage." << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << "Destructor called to destroy DiamondTrap " << _name << std::endl;
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap's name is " << _name << " and ClapTrap's name is " << ClapTrap::_name << std::endl;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}