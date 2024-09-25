
#include "Contact_Class.hpp"
#include "PhoneBook_Class.hpp"

int main()
{
    PhoneBook   phoneBook;
    std::string input_cmd;

    while (true)
    {
        // std::cin.clear();
        std::cout << "Que souhaitez vous faire dans le répertoire ? " << std::endl;
        // std::cin >> input_cmd;
        std::getline(std::cin, input_cmd);
        if (input_cmd == "ADD")
            phoneBook.addContact();
        else if (input_cmd == "SEARCH")
            phoneBook.searchContact();
        else if (input_cmd == "EXIT")
            break ;
        else
            std::cout << "Invalid command entered !" << std::endl;
    }
    return 0;
}

// TESTS : 
// - Pb de boucle infinie si index == texte => DONE
// - Pb si je ne rentre rien dans un champ crée qd même le contact => DONE
// - Prévoir qqe chose si pas de contact mais SEARCH avec un index ?
// - Pb quand j'affiche un contact, qd je reviens dans le main j'ai une erreur avant de pouvoir remettre une input.
// TO DO : ADD _ to my private attributs.