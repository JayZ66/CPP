
#include "Contact_Class.hpp"
#include "PhoneBook_Class.hpp"

std::string	getline_error(std::string input)
{
	std::string	new_input;

	if (input.empty())
	{
		std::cout << "Le champ est vide, veuillez le remplir: ";
		std::getline(std::cin, new_input);
		return new_input;
	}
	else
		return input;
}

void	PhoneBook::addContact()
{
	int			index;
	std::string firstname_input;
    std::string lastname_input;
    std::string nickname_input;
    std::string phone_input;
    std::string darkestsecret_input;
	index = _count % 8;
	// if (count < 8)
	// {
		// char	buff[512];

		std::cout << "Entrez le prénom du contact: ";
		std::getline(std::cin, firstname_input);
		firstname_input = getline_error(firstname_input);
		contacts[index].setFirstname(firstname_input);

		std::cout << "Entrez le nom du contact: ";
		std::getline(std::cin, lastname_input);
		lastname_input = getline_error(lastname_input);
		contacts[index].setLastname(lastname_input);

		std::cout << "Entrez le surnom du contact: ";
		std::getline(std::cin, nickname_input);
		nickname_input= getline_error(nickname_input);
		contacts[index].setNickname(nickname_input);

		std::cout << "Entrez le numéro de téléphone du contact: ";
		std::getline(std::cin, phone_input);
		phone_input = getline_error(phone_input);
		contacts[index].setPhonenumber(phone_input);

		std::cout << "Entrez le secret le plus dark du contact: ";
		std::getline(std::cin, darkestsecret_input);
		darkestsecret_input = getline_error(darkestsecret_input);
		contacts[index].setDarkestsecret(darkestsecret_input);
		_count++;
}

// std::setw : Specifie la largeur du champ d'aff. pour le next element.
void	PhoneBook::searchContact()
{
	int	i;

	i = 0;
	if (_count == 0) {
		std::cout << "There is not contact to display !" << std::endl;
		return ;
	}
	while (i < 8)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getFirstname()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getLastname()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
		i++;
	}

	int	input_index;
	std::string	index_line;
	std::cout << "Entrez l'index du contact souhaité: ";
	while (true)
	{
		std::getline(std::cin, index_line);
		std::stringstream	ss(index_line);
		if (ss >> input_index && ss.eof() && input_index >= 0 && input_index < _count) // Can check errors directly with cin !! Sending it in getline & checking errors with cin bce checking what's in the std input !
		{
			std::cout << "Prénom: " << contacts[input_index].getFirstname() << std::endl;
			std::cout << "Nom: " << contacts[input_index].getLastname() << std::endl;
			std::cout << "Surnom: " << contacts[input_index].getNickname() << std::endl;
			std::cout << "Numéro de téléphone: " << contacts[input_index].getPhonenumber() << std::endl;
			std::cout << "Secret: " << contacts[input_index].getDarkestsecret() << std::endl;
			break ;
		}
		else
			std::cout << "L'index entré n'est pas bon. Veuillez entrer un nombre valide: ";
	}
}

std::string truncate(const std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
