
#pragma once

#include <iostream>
#include <stdexcept> // for std::runtime_error();
#include <string>


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

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return ("Grade is too high !");
            }
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return ("Grade is too low !");
            }
    };

};

std::ostream&   operator<<(std::ostream& info, const Bureaucrat& other);