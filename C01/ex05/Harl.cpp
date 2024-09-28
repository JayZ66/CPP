
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

void    Harl::complain( std::string level )
{
    void    (Harl::*ptrComplain[])() = { 
                &Harl::debug, 
                &Harl::info, 
                &Harl::warning, 
                &Harl::error 
    };
     std::string levels[4] = {
                "DEBUG",
                "INFO",
                "WARNING",
                "ERROR"
    };
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level) {
            (this->*ptrComplain[i])(); // Last bracket : bce no param. in the function pointed.
            return ;
        }
    }
    std::cout << "This complain is not existing !" << std::endl;
}

/*
Pourquoi utiliser this dans ce cas précis :

Dans ton code, this est un pointeur vers l'objet courant. 
Il est nécessaire lorsque tu veux appeler une fonction membre 
à partir d'un pointeur vers une fonction membre.

Dans ta classe Harl, les méthodes comme debug(), info(), 
warning(), et error() sont des méthodes membres. 
Quand tu crées un tableau de pointeurs vers ces fonctions, 
tu ne peux pas les appeler directement comme des fonctions 
normales. Elles doivent être appelées sur un objet particulier 
(l'objet actuel sur lequel tu travailles), c'est là que this 
entre en jeu.

Donc, lorsque tu fais :

(this->*ptrComplain[i])();

Cela signifie :

    this-> : Prends le pointeur vers l'objet actuel.
    *ptrComplain[i] : Déréférence le pointeur vers la fonction 
    membre à l'index i.
    () : Exécute cette fonction sur l'objet this.

Quand faut-il utiliser this ?

    1. Quand tu veux accéder à l'objet courant :
        Si tu veux accéder aux attributs ou méthodes de la 
        classe à partir d'une méthode membre, le compilateur 
        l'interprète automatiquement, donc tu n'as pas toujours 
        besoin de spécifier this explicitement. Par exemple, 
        écrire myAttribute et this->myAttribute est souvent 
        équivalent dans une méthode membre.

    2. Quand tu passes un pointeur à une méthode membre :
    Comme dans ton cas, si tu utilises des pointeurs vers des 
    fonctions membres, tu dois utiliser this pour appeler la 
    méthode à travers un pointeur.

    3. Pour distinguer un paramètre d'un attribut :
    Si le nom d'un paramètre de fonction est identique à celui 
    d'un attribut de la classe, tu peux utiliser this pour 
    différencier l'attribut de l'objet et le paramètre de la 
    fonction.

    class MyClass {
        int myAttribute;
    public:
        void setAttribute(int myAttribute) {
            this->myAttribute = myAttribute;  // Ici, "this->myAttribute" se réfère à l'attribut de la classe
        }
    };

Quand ne pas utiliser this :

    Accès implicite aux membres :
    Quand tu accèdes à un membre sans conflit de nom, tu n'as 
    pas besoin d'utiliser this. Le compilateur sait que tu 
    parles de l'attribut de l'objet courant.
        Exemple : myAttribute = 5; est équivalent à this->myAttribute = 5; si aucun paramètre local n'a le même nom.

En résumé, tu utilises this quand tu as besoin d'accéder 
explicitement à l'objet courant, notamment dans le contexte de 
pointeurs sur membres ou pour désambiguïser les noms de 
variables.
*/
