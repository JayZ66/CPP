
#pragma once

#include <ostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:

		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
	AForm();
	AForm(std::string pname, const int pgradeToSign, const int pGradeToExecute);
	virtual~AForm();

	AForm(const Form& other);
	AForm& operator=(const Form& other);

	virtual	void	execute(const Bureaucrat& executor) const = 0; // Pure virtual method to have an abstract class.

	void	beSigned(Bureaucrat& bureaucrat);

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	class GradeTooHighException : public std::exception {
		private:
			std::string _message;
		
		public :
			GradeTooHighException(std::string message) : _message(message) {};
			virtual ~GradeTooHighException() throw() {};
			virtual const char* what() const throw() {
				return _message.c_str();
			}
	};

	class GradeTooLowException : public std::exception {
		private:
			std::string _message;
		
		public:
			GradeTooLowException(std::string message) : _message(message) {};
			virtual ~GradeTooLowException() throw() {};
			virtual const char* what() const throw() {
				return _message.c_str();
			}
	};
};

std::ostream& operator<<(std::ostream& info, const Form& other);
