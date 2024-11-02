
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
		
		Intern	badIntern;
		AForm*	newForm = badIntern.makeForm("ShrubberyCreation", "target");

		if (newForm) {
			std::cout << newForm.getName() << " has been created !" << std::endl;
			delete newForm;
		}

		std::cout << std::endl <<  "-------------------- OTHER TEST -------------------- " << std::endl << std::endl;
		
	
	

	return 0;
}