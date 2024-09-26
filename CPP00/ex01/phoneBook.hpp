/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:45:37 by hnagasak          #+#    #+#             */
/*   Updated: 2024/09/26 19:44:55 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include "contact.hpp"
#include <sstream>
#include <iomanip>
#include <cstdlib>

#define CONTACT_NUM_MAX 8

class PhoneBook {
  private:
		// void _putContact(Contact& contact);
		// int _numberEntry();
		void _putContact(Contact& contact);
		// void _getValidatedInput(std::string& input, const std::string& msg);
		std::string _truncateString(const std::string& str, size_t maxLen);
		// int _findContactIndex(Contact contacts[CONTACT_NUM_MAX], int id);
    void _putRow(int index, Contact& contact); 
    int _inputIndex();
    
		int _totalContacts;
		Contact _contacts[CONTACT_NUM_MAX];
    std::string _inputString(const std::string& msg);
  
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
		void exit();
};

#endif
