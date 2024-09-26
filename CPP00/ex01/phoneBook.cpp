/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:47:44 by hnagasak          #+#    #+#             */
/*   Updated: 2024/09/26 21:16:25 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

PhoneBook::PhoneBook() : _totalContacts(0)
{
  std::cout << "PhoneBook object created" << std::endl;
}

PhoneBook::~PhoneBook()
{
  std::cout << "PhoneBook object destroyed" << std::endl;
}

std::string PhoneBook::_inputString(const std::string &msg)
{
  std::string input;
  std::cout << msg;
  while (input.empty())
  {
    if (std::getline(std::cin, input).eof())
      std::exit(0);
  }
  return (input);
}

void PhoneBook::add()
{
  int id;

  std::string input;
  id = this->_totalContacts % CONTACT_NUM_MAX;
  this->_totalContacts++;
  std::string firstName = this->_inputString("Please enter First Name\t\t: ");
  std::string lastName = this->_inputString("Please enter Last Name\t\t: ");
  std::string nickname = this->_inputString("Please enter Nickname\t\t: ");
  std::string phoneNumber = this->_inputString("Please enter PhoneNumber\t: ");
  std::string darkestSecret = this->_inputString("Please enter DarkestSecret\t: ");
  this->_contacts[id].setFirstName(firstName);
  this->_contacts[id].setLastName(lastName);
  this->_contacts[id].setNickname(nickname);
  this->_contacts[id].setPhoneNumber(phoneNumber);
  this->_contacts[id].setDarkestSecret(darkestSecret);
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
    std::cout << std::setw(10) << std::right << _truncateString(contact.getFirstName(),9) << "|";
    std::cout << std::setw(10) << std::right << _truncateString(contact.getLastName(),9) << "|";
    std::cout << std::setw(10) << std::right << _truncateString(contact.getNickname(),9) << "|";
    std::cout << std::endl;
}

int PhoneBook::_inputIndex() {
    int id = 0;
    std::stringstream ss;
    std::string str;

    while (true) {
        std::cout << "Enter the index of the contact: ";
        std::getline(std::cin, str);
        if (std::cin.eof()) {
            std::cout << "EOF detected. Exiting the program." << std::endl;
            std::exit(EXIT_SUCCESS);
        }
        ss << str;
        if (ss >> id) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }
    }
    return id;
}



void PhoneBook::search()
{
  if (this->_totalContacts == 0)
  {
    std::cout << "There are no contacts in the phone book." << std::endl;
    return;
  }
  std::cout << std::setw(10) << std::right << "index"
            << "|";
  std::cout << std::setw(10) << std::right << "first name"
            << "|";
  std::cout << std::setw(10) << std::right << "last name"
            << "|";
  std::cout << std::setw(10) << std::right << "nickname"
            << "|";
  std::cout << std::endl;
  for (int i = 0; i < this->_totalContacts; i++)
  {
    this->_putRow(i,this->_contacts[i]);
  }
  
  while (true)
  {
    int targetIndex = this->_inputIndex();
    if (targetIndex >= 0 && targetIndex < this->_totalContacts)
    {
      this->_putContact(this->_contacts[targetIndex]);
      break;
    }
    else
    {
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

void PhoneBook::exit()
{
  return;
}
