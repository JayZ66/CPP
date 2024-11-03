
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {
		
		Intern	badIntern;
		AForm*	newForm = badIntern.makeForm("ShrubberyCreationForm", "target");

		if (newForm) {
			std::cout << *newForm << std::endl;
			std::cout << newForm->getName() << " has been created !" << std::endl;
			Bureaucrat	Director("Gero", 20);
			std::cout << Director << std::endl;
			Director.signForm(*newForm);
			Director.executeForm(*newForm);

			delete newForm;
		}

		std::cout << std::endl <<  "-------------------- ERROR TEST -------------------- " << std::endl << std::endl;
		
		Intern	internOfTheMonth;
		AForm*	contract = internOfTheMonth.makeForm("PresidentialPardonForm", "target2");

		if (contract) {
			std::cout << *contract << std::endl;
			std::cout << contract->getName() << " has been created !" << std::endl;
			Bureaucrat	imposter("Luc", 20);
			std::cout << imposter << std::endl;

			imposter.signForm(*contract);
			imposter.executeForm(*contract);

			delete contract;
		}

		std::cout << std::endl <<  "-------------------- OTHER TEST -------------------- " << std::endl << std::endl;

		Intern	internAgain;
		AForm*	diary = internAgain.makeForm("RobotomyRequestForm", "target4");

		if (diary) {
			std::cout << *diary << std::endl;
			std::cout << diary->getName() << " has been created !" << std::endl;
			Bureaucrat	iRobot("Wall-e", 35);
			std::cout << iRobot << std::endl;

			iRobot.signForm(*diary);
			iRobot.executeForm(*diary);

			delete diary;
		}

		std::cout << std::endl <<  "-------------------- ERROR TEST -------------------- " << std::endl << std::endl;

		Intern	lastIntern;
		AForm*	notFound = lastIntern.makeForm("UnknownForm", "target5");

		if (!notFound) {
			std::cerr << "No form has been created because of invalid form name !" << std::endl;
		}

	return 0;
}