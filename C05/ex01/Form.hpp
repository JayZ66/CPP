
#pragma once

#include <ostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:

		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
	Form();
	Form(std::string pname, const int pgradeToSign, const int pGradeToExecute);
	~Form();

	Form(const Form& other);
	Form& operator=(const Form& other);

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
