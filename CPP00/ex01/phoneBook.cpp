/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:47:44 by hnagasak          #+#    #+#             */
/*   Updated: 2024/09/30 20:51:44 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

PhoneBook::PhoneBook() : _nextIndex(0){
  std::cout << "PhoneBook object created" << std::endl;
}

PhoneBook::~PhoneBook(){
  std::cout << "PhoneBook object destroyed" << std::endl;
}

std::string PhoneBook::_inputString(const std::string &msg){
  std::string input;
  std::cout << msg;
  while (input.empty())
  {
    std::getline(std::cin, input);
    if(std::cin.eof())
      std::exit(EXIT_SUCCESS);
  }
  return (input);
}

void PhoneBook::add(){
  int idx;

  std::string input;
  idx = this->_nextIndex;
  std::string firstName = this->_inputString("Please enter First Name\t\t: ");
  std::string lastName = this->_inputString("Please enter Last Name\t\t: ");
  std::string nickname = this->_inputString("Please enter Nickname\t\t: ");
  std::string phoneNumber = this->_inputString("Please enter PhoneNumber\t: ");
  std::string darkestSecret = this->_inputString("Please enter DarkestSecret\t: ");
  this->_contacts[idx].setFirstName(firstName);
  this->_contacts[idx].setLastName(lastName);
  this->_contacts[idx].setNickname(nickname);
  this->_contacts[idx].setPhoneNumber(phoneNumber);
  this->_contacts[idx].setDarkestSecret(darkestSecret);
  this->_nextIndex = (this->_nextIndex + 1) % CONTACT_NUM_MAX;
}

std::string PhoneBook::_truncateString(const std::string& str, size_t maxLen) {
  if (str.length() <= maxLen) {
    return str;
  } else {
    std::string ret = str.substr(0, maxLen - 1);
    return ret + ".";
  }
}

void PhoneBook::_putRow(int index, Contact& contact) {
  std::cout << std::setw(10) << std::right << index << "|";
  std::cout << std::setw(10) << std::right << _truncateString(contact.getFirstName(),10) << "|";
  std::cout << std::setw(10) << std::right << _truncateString(contact.getLastName(),10) << "|";
  std::cout << std::setw(10) << std::right << _truncateString(contact.getNickname(),10) << "|";
  std::cout << std::endl;
}

int PhoneBook::_inputIndex() {
  int idx = 0;
  std::string str;

  while (true) {
        std::cout << "Enter the index of the contact: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            std::exit(EXIT_SUCCESS);        
        std::stringstream ss;
        ss << str;
        if (ss >> idx) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }
    }
    return idx;
}



void PhoneBook::search()
{
  std::cout << std::setw(10) << std::right << "index" << "|";
  std::cout << std::setw(10) << std::right << "first name" << "|";
  std::cout << std::setw(10) << std::right << "last name" << "|";
  std::cout << std::setw(10) << std::right << "nickname" << "|";
  std::cout << std::endl;
  
  for (int i = 0; i < CONTACT_NUM_MAX; i++){
    this->_putRow(i,this->_contacts[i]);
  }
  
  while (true){
    int targetIndex = this->_inputIndex();
    if (targetIndex >= 0 && targetIndex < CONTACT_NUM_MAX) {
      this->_putContact(this->_contacts[targetIndex]);
      break;
    } else {
      std::cout << "Please enter a valid value." << std::endl;
    }
  }
}

void PhoneBook::_putContact(Contact& contact) {
  std::cout << "first name\t: " << contact.getFirstName() << std::endl;
  std::cout << "last name\t: " << contact.getLastName() << std::endl;
  std::cout << "nickname\t: " << contact.getNickname() << std::endl;
  std::cout << "phone number\t: " << contact.getPhoneNumber() << std::endl;
  std::cout << "darkest secret\t: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::exit(){
  return;
}
