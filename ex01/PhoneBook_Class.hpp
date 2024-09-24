#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <string>
#include <limits>

std::string truncate(const std::string str);

class   PhoneBook {
private:
    Contact contacts[8];
    int     count;

public:
    PhoneBook() : count(0) {}
    // ~PhoneBook(void);
    void    addContact();
    void    searchContact();

};

#endif