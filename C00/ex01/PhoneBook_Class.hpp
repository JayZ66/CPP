#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <limits>

std::string truncate(const std::string str);

class   PhoneBook {
private:
    Contact contacts[8];
    int     _count;

public:
    PhoneBook() : _count(0) {}
    // ~PhoneBook(void);
    void    addContact();
    void    searchContact();

};

#endif