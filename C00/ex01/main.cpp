
#include "Contact_Class.hpp"
#include "PhoneBook_Class.hpp"

int main()
{
    PhoneBook   phoneBook;
    std::string input_cmd;

    while (true)
    {
        std::cout << "Que souhaitez vous faire dans le répertoire ? " << std::endl;
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
