
#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	Manager("Teddix", 30);

	while (true) {
		try {
			Manager.incrementGrade();
			std::cout << Manager << std::endl; // Using << operator.
		}
		catch (const GradeTooHighException& e) {
			std::cerr << "Echec de l'incrementation du Grade de " << Manager.getName() << " : " << e.what() << std::endl;
			break ;
		}
	}
	std::cout << std::endl <<  "-------------------- DECREMENTATION -------------------- " << std::endl << std::endl;
	
	Bureaucrat	Salarie("Antonus", 100);

	while (true)
	{
		try {
			Salarie.decrementGrade();
			std::cout << Salarie << std::endl; // Using << operator.
		}
		catch (const GradeTooLowException& e) {
			std::cerr << "Echec de la decrementation du Grade de " << Salarie.getName() << " : " << e.what() << std::endl;
			break ;
		}
	}
	

	return 0;
}