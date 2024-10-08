
#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>

class   Contact {
private:
    std::string _lastname;
    std::string _firstname;
    std::string _nickname;
    std::string _phonenumber;
    std::string _darkestsecret;

public:
    Contact() : _lastname(""), _firstname(""), _nickname(""), _phonenumber(""), _darkestsecret("") {}
    Contact(std::string p_lastname, std::string p_firstname, std::string p_nickname, std::string p_phonenumber, std::string p_darkestsecret);
    // ~Contact(void);

    std::string getLastname() const;
    std::string getFirstname() const;
    std::string getNickname() const;
    std::string getPhonenumber() const;
    std::string getDarkestsecret() const;
    
    void    setLastname(std::string p_lastname);
    void    setFirstname(std::string p_firstname);
    void    setNickname(std::string p_nickname);
    void    setPhonenumber(std::string p_phonenumber);
    void    setDarkestsecret(std::string p_darkestsecret);

};

#endif