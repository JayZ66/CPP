
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {

	srand(time(NULL)); // Init one time to obtain random results each time.
	
	try {
		Bureaucrat	President("Macron", 3);
		std::cout << President << std::endl;
		PresidentialPardonForm	contract("target");
		std::cout << contract << std::endl;

		President.signForm(contract);
		President.executeForm(contract);

		std::cout << std::endl <<  "-------------------- OTHER TEST -------------------- " << std::endl << std::endl;
		Bureaucrat	OldPresident("Holland", 145);
		std::cout << OldPresident << std::endl;
		ShrubberyCreationForm	form("target2");
		std::cout << form << std::endl;

		OldPresident.signForm(form);
		OldPresident.executeForm(form);

		std::cout << std::endl <<  "-------------------- OTHER TEST -------------------- " << std::endl << std::endl;
		Bureaucrat	oldFirstLady("Valérie", 100);
		std::cout << oldFirstLady << std::endl;
		ShrubberyCreationForm	divorce("Hollande");
		std::cout << divorce << std::endl;

		oldFirstLady.signForm(divorce);
		oldFirstLady.executeForm(divorce);

		std::cout << std::endl <<  "-------------------- OTHER TEST -------------------- " << std::endl << std::endl;
		Bureaucrat	FirstLady("Brigitte", 40);
		std::cout << FirstLady << std::endl;
		RobotomyRequestForm	mariage("Macron");
		std::cout << mariage << std::endl;

		FirstLady.signForm(mariage);
		FirstLady.executeForm(mariage);

		std::cout << std::endl <<  "-------------------- OTHER TEST -------------------- " << std::endl << std::endl;
		Bureaucrat	newPresident("JayZ", 30);
		std::cout << newPresident << std::endl;
		PresidentialPardonForm scam("Elysée");
		std::cout << scam << std::endl;

		newPresident.signForm(scam);
		newPresident.executeForm(scam);

	}
	catch (const std::exception& e) {
		std::cerr << "An error has been caught: " << e.what() << std::endl;
	}
	
	

	return 0;
}