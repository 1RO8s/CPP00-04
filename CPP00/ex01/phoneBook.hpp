/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:45:37 by hnagasak          #+#    #+#             */
/*   Updated: 2024/09/30 20:39:19 by hnagasak         ###   ########.fr       */
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
	  void _putContact(Contact& contact);
	  std::string _truncateString(const std::string& str, size_t maxLen);
    void _putRow(int index, Contact& contact); 
    int _inputIndex();
    int _nextIndex;
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
