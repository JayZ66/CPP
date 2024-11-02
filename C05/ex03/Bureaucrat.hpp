
#pragma once

#include <iostream>
#include <stdexcept> // for std::runtime_error();
#include <string>
#include <ostream>
#include "AForm.hpp"

class AForm;

class   Bureaucrat {
    private:
    const std::string   _name;
    int                 _grade;

    public:
    Bureaucrat();
    Bureaucrat(std::string pname, int pgrade); // Check if necessary
    ~Bureaucrat();

    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    
    int getGrade() const;
    std::string getName() const;

    void    incrementGrade();
    void    decrementGrade();

    void    signForm(AForm &form);
    void    executeForm(const AForm& form);


    class GradeTooHighException : public std::exception {
    public:
        GradeTooHighException(const std::string& message) : _message(message) {}
        virtual ~GradeTooHighException() throw() {}
        virtual const char* what() const throw() {
            return _message.c_str();
         }
    private:
        std::string _message;
};

class GradeTooLowException : public std::exception {
     public:
        GradeTooLowException(const std::string& message) : _message(message) {}
        virtual ~GradeTooLowException() throw() {}
        virtual const char* what() const throw() {
            return _message.c_str();
        }
    private:
        std::string _message;
 };

};

std::ostream&   operator<<(std::ostream& info, const Bureaucrat& other);