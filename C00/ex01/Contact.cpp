/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:23:09 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/01 10:23:10 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact_Class.hpp"
#include "PhoneBook_Class.hpp"


Contact::Contact(std::string p_lastname, std::string p_firstname, std::string p_nickname, std::string p_phonenumber, std::string p_darkestsecret)
    : _lastname(p_lastname), _firstname(p_firstname), _nickname(p_nickname), _phonenumber(p_phonenumber), _darkestsecret(p_darkestsecret) {}


std::string Contact::getLastname() const {
        return _lastname;
    }
    std::string Contact::getFirstname() const {
        return _firstname;
    }
    std::string Contact::getNickname() const {
        return _nickname;
    }
    std::string Contact::getPhonenumber() const {
        return _phonenumber;
    }
    std::string Contact::getDarkestsecret() const {
        return _darkestsecret;
    }
    
    void    Contact::setLastname(std::string p_lastname) {
        if (p_lastname.empty())
            std::cout << "Le nom ne peut être vide." << std::endl;
        else
            _lastname = p_lastname;
    }
    void    Contact::setFirstname(std::string p_firstname) {
        if (p_firstname.empty())
            std::cout << "Le prénom ne peut être vide." << std::endl;
        else
            _firstname = p_firstname;
    }
    void    Contact::setNickname(std::string p_nickname) {
        if (p_nickname.empty())
            std::cout << "Le surnom ne peut être vide." << std::endl;
        else
            _nickname = p_nickname;
    }
    void    Contact::setPhonenumber(std::string p_phonenumber) {
        if (p_phonenumber.empty())
            std::cout << "Le numéro de téléphone ne peut être vide." << std::endl;
        else
            _phonenumber = p_phonenumber;
    }
    void    Contact::setDarkestsecret(std::string p_darkestsecret) {
        if (p_darkestsecret.empty())
            std::cout << "Le code secret ne peut être vide." << std::endl;
        else
            _darkestsecret = p_darkestsecret;
    }