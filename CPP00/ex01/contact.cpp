/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:42:58 by hnagasak          #+#    #+#             */
/*   Updated: 2024/09/30 20:49:05 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(): _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret("") {
    std::cout << "Contact object created" << std::endl;
}

Contact::~Contact() {
    std::cout << "Contact object destroyed" << std::endl;
}

void Contact::setFirstName(std::string firstName) {
    this->_firstName = firstName;
}

std::string Contact::getFirstName() {
    return this->_firstName;
}

void Contact::setLastName(std::string lastName) {
    this->_lastName = lastName;
}

std::string Contact::getLastName() {
    return this->_lastName;
}

void Contact::setNickname(std::string nickName) {
    this->_nickName = nickName;
}

std::string Contact::getNickname() {
    return this->_nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
    this->_phoneNumber = phoneNumber;
}

std::string Contact::getPhoneNumber() {
    return this->_phoneNumber;
}

void Contact::setDarkestSecret(std::string drakestSecret) {
    this->_darkestSecret = drakestSecret;
}

std::string Contact::getDarkestSecret() {
    return this->_darkestSecret;
}
