
#include "Bureaucrat.hpp"

int	main() {

	try {
		Bureaucrat	Manager("Teddix", 30); // USEFUL TO CREATE INSTANCE IN TRY ??
		std::cout << Manager << std::endl;
		Form		contract("Pokemon", 50, 130);
		std::cout << contract << std::endl;


		Manager.incrementGrade();
		std::cout << Manager << std::endl;
		Manager.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (const std::exception& e) { // Will caught any exception encountered.
		std::cerr << "Exception caught: " << e.what() << std::endl; // Will print the specific exception thx to the ref.
	}

std::cout << std::endl <<  "-------------------- ERROR TEST -------------------- " << std::endl << std::endl;
	
	try {
		Bureaucrat	Employee("Carole", 120);
		std::cout << Employee << std::endl;
		Form		scam("scam", 100, 140);
		std::cout << scam << std::endl;

		Employee.incrementGrade();
		std::cout << Employee << std::endl;
		Employee.signForm(scam);
		std::cout << scam << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}