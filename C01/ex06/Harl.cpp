
#include "Harl.hpp"

void    Harl::debug( void )
{
    std::cout << " I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;

}

void    Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    void    (Harl::*ptrComplain[])() = { 
                &Harl::debug,
                &Harl::info,
                &Harl::warning,
                &Harl::error,
    };
    std::string levels[4] = {
                "DEBUG",
                "INFO",
                "WARNING",
                "ERROR",
    };
    int levelIndex = -1;
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
            levelIndex = i;
    }
    switch (levelIndex) {
        case 0:
            (this->*ptrComplain[0])();
            // fall through
        case 1:
            (this->*ptrComplain[1])();
            // fall through
        case 2:
            (this->*ptrComplain[2])();
            // fall through
        case 3:
            (this->*ptrComplain[3])();
            break ;
        default:
            std::cout << "This complain is not existing !" << std::endl;
    }

}

/*
SWITCH : 
1. Comportement normal du switch avec des break

Chaque case dans un switch est un point de décision.
Quand le switch compare l'expression (dans ton cas, 
indexComplain) avec les valeurs des case, il commence à 
exécuter le code du case qui correspond à cette valeur.
Le break arrête l'exécution et sort du switch. Il empêche le 
programme de continuer à exécuter les autres case après celui 
qui a été trouvé.

2. Comportement sans break

Sans break, le programme continue d'exécuter tous les case qui 
suivent celui qui a été trouvé, indépendamment de leur valeur. 
Cela s'appelle un "fall-through".
*/

// fall through > to skip the compilation error when not using
// break for each case ! (downfall effect : passing through each case)