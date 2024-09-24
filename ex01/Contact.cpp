#include "Contact_Class.hpp"
#include "PhoneBook_Class.hpp"


Contact::Contact(std::string p_lastname, std::string p_firstname, std::string p_nickname, std::string p_phonenumber, std::string p_darkestsecret)
    : lastname(p_lastname), firstname(p_firstname), nickname(p_nickname), phonenumber(p_phonenumber), darkestsecret(p_darkestsecret) {}


std::string Contact::getLastname() const {
        return lastname;
    }
    std::string Contact::getFirstname() const {
        return firstname;
    }
    std::string Contact::getNickname() const {
        return nickname;
    }
    std::string Contact::getPhonenumber() const {
        return phonenumber;
    }
    std::string Contact::getDarkestsecret() const {
        return darkestsecret;
    }
    
    void    Contact::setLastname(std::string p_lastname) {
        if (p_lastname.empty())
            std::cout << "Le nom ne peut être vide." << std::endl;
        else
            lastname = p_lastname;
    }
    void    Contact::setFirstname(std::string p_firstname) {
        if (p_firstname.empty())
            std::cout << "Le prénom ne peut être vide." << std::endl;
        else
            firstname = p_firstname;
    }
    void    Contact::setNickname(std::string p_nickname) {
        if (p_nickname.empty())
            std::cout << "Le surnom ne peut être vide." << std::endl;
        else
            nickname = p_nickname;
    }
    void    Contact::setPhonenumber(std::string p_phonenumber) {
        if (p_phonenumber.empty())
            std::cout << "Le numéro de téléphone ne peut être vide." << std::endl;
        else
            phonenumber = p_phonenumber;
    }
    void    Contact::setDarkestsecret(std::string p_darkestsecret) {
        if (p_darkestsecret.empty())
            std::cout << "Le code secret ne peut être vide." << std::endl;
        else
            darkestsecret = p_darkestsecret;
    }