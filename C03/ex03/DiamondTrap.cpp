

#include "DiamondTrap.hpp"

// Give the new name to ClapTrap through its constructor and modify the name as it's
// the same that DiamondTrap which heritates from ClapTrap, it could be a pb.
/*
Pour initialiser correctement le nom dans ClapTrap, il faut utiliser la liste d'initialisation 
et passer le nom modifié (avec le suffixe) au constructeur de ClapTrap.
*/
DiamondTrap::DiamondTrap( const std::string& _pname ) : ClapTrap(_pname + "_clap_name"), ScavTrap(_pname), FragTrap(_pname), _name(_pname)
{
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "Default constructor called, DiamondTrap name is " << _name << ", it has " << _hitPoints << " hit points, " << _energyPoints << " energy points and " << _attackDamage << " attack damage." << std::endl;

}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << "Destructor called to destroy DiamondTrap " << _name << std::endl;
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap's name is " << _name << " and ClapTrap name is " << ClapTrap::_name << std::endl;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}



/*
EXPLICATIONS : DiamondTrap::DiamondTrap( const std::string& _pname ) : ClapTrap(_pname + "_clap_name"), ScavTrap(_pname), FragTrap(_pname), _name(_pname)
Si je n'appelle pas les constructeurs de FragTrap et ScavTrap.

Pourquoi les constructeurs des classes de base doivent être appelés
Initialisation des sous-objets : En C++, lorsqu'une classe dérivée est instanciée, elle 
contient automatiquement des instances des classes de base. Cela signifie que chaque fois que 
tu crées un objet de type DiamondTrap, des objets de type ScavTrap et FragTrap sont également 
créés à l'intérieur de DiamondTrap. Pour que ces objets soient correctement initialisés, il est 
essentiel d'appeler leurs constructeurs. Si tu ne le fais pas, le compilateur ne saura pas 
comment initialiser ces sous-objets, ce qui entraîne des erreurs de lien (undefined references) 
lorsque tu essaies d'utiliser les membres de ces classes.

Constructeur par défaut : Si tu n'appelles pas explicitement le constructeur d'une classe de 
base dans le constructeur de la classe dérivée, le compilateur tentera d'appeler le constructeur 
par défaut de cette classe de base. Si un constructeur par défaut n'est pas défini dans ScavTrap 
ou FragTrap, cela provoquera une erreur de liaison, car le compilateur ne peut pas trouver de 
définition pour ce constructeur.

Passage des paramètres : Dans ton cas, 
lorsque tu écris DiamondTrap::DiamondTrap( const std::string& _pname ), tu dois spécifier 
comment initialiser chaque classe de base. Tu as utilisé ClapTrap(_pname + "_clap_name") pour 
initialiser ClapTrap, mais tu n'as pas fait de même pour ScavTrap et FragTrap. Par conséquent, 
les constructeurs de ces classes n'étaient pas appelés, ce qui a provoqué les erreurs de liaison.

Ce qui se passe sous le capot lorsque tu déclares ton constructeur comme suit :

DiamondTrap::DiamondTrap( const std::string& _pname )
Le compilateur sait que tu as une hiérarchie d'héritage avec plusieurs classes de base. 

Ainsi, pour créer un objet de type DiamondTrap, il doit :
- Appeler le constructeur de ClapTrap (la première classe de base).
- Appeler le constructeur de ScavTrap.
- Appeler le constructeur de FragTrap.

Si tu ne spécifies pas ces appels dans la liste d'initialisation, le compilateur essaiera de trouver le constructeur par défaut, qui peut ne pas exister, entraînant ainsi des erreurs de liaison.
*/