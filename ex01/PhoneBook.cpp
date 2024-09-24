
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

	index = count % 8;
	// if (count < 8)
	// {
		// char	buff[512];

		std::cout << "Entrez le prénom du contact: ";
		// std::cin >> buff;
		std::getline(std::cin, firstname_input);
		firstname_input = getline_error(firstname_input);
		contacts[index].setFirstname(firstname_input);

		std::cout << "Entrez le nom du contact: ";
		// std::cin >> buff;
		std::getline(std::cin, lastname_input);
		lastname_input = getline_error(lastname_input);
		contacts[index].setLastname(lastname_input);

		std::cout << "Entrez le surnom du contact: ";
		// std::cin >> buff;
		std::getline(std::cin, nickname_input);
		nickname_input= getline_error(nickname_input);
		contacts[index].setNickname(nickname_input);

		std::cout << "Entrez le numéro de téléphone du contact: ";
		// std::cin >> buff;
		std::getline(std::cin, phone_input);
		phone_input = getline_error(phone_input);
		contacts[index].setPhonenumber(phone_input);

		std::cout << "Entrez le secret le plus dark du contact: ";
		// std::cin >> buff;
		std::getline(std::cin, darkestsecret_input);
		darkestsecret_input = getline_error(darkestsecret_input);
		contacts[index].setDarkestsecret(darkestsecret_input);
		count++;
	// }
	// else
	// {
	// 	char	buff[512];

	// 	std::cout << "Entrez le prénom du contact: ";
	// 	std::cin >> buff;
	// 	contacts[count % 8].setFirstname(buff);

	// 	std::cout << "Entrez le nom du contact: ";
	// 	std::cin >> buff;
	// 	contacts[count % 8].setLastname(buff);

	// 	std::cout << "Entrez le surnom du contact: ";
	// 	std::cin >> buff;
	// 	contacts[count % 8].setNickname(buff);

	// 	std::cout << "Entrez le numéro de téléphone du contact: ";
	// 	std::cin >> buff;
	// 	contacts[count % 8].setPhonenumber(buff);

	// 	std::cout << "Entrez le secret le plus dark du contact: ";
	// 	std::cin >> buff;
	// 	contacts[count % 8].setDarkestsecret(buff);
	// 	count++;
	// }
}

void	PhoneBook::searchContact()
{
	int	i;

	i = 0;
	while (i < count)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getFirstname()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getLastname()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getNickname());
		std::cout << std::endl;
		i++;
	}

	int	input_index;

	std::cout << "Entrez l'index du contact souhaité: ";
	while (1)
	{
		std::cin >> input_index;  // Need to use cin because it's an int !
		if (std::cin.fail())
		{
			std::cin.clear(); // Réinitialiser flux d'entrée.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer le reste de l'entrée.
			std::cout << "Veuillez entrer un nombre valide: ";
			continue ;
		}

		if (input_index < 0 || input_index >= count)
			std::cout << "L'index entré n'est pas bon. Veuillez entrer un nombre valide: ";
		else
		{
			std::cout << "Prénom: " << contacts[input_index].getFirstname() << std::endl;
			std::cout << "Nom: " << contacts[input_index].getLastname() << std::endl;
			std::cout << "Surnom: " << contacts[input_index].getNickname() << std::endl;
			std::cout << "Numéro de téléphone: " << contacts[input_index].getPhonenumber() << std::endl;
			std::cout << "Secret: " << contacts[input_index].getDarkestsecret() << std::endl;
			break ;
		}
	}
}

std::string truncate(const std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
