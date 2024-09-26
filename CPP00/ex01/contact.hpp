/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:55:57 by hnagasak          #+#    #+#             */
/*   Updated: 2024/09/26 16:56:37 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact();
    ~Contact();
    void setFirstName(std::string firstName);
		std::string getFirstName();
		void setLastName(std::string lastName);
		std::string getLastName();
		void setNickname(std::string nickname);
		std::string getNickname();
		void setPhoneNumber(std::string phoneNumber);
		std::string getPhoneNumber();
		void setDarkestSecret(std::string drakestSecret);
		std::string getDarkestSecret();
    // void set_contact(std::string first_name,
    //                  std::string last_name,
    //                  std::string nickname,
    //                  std::string phone_number,
    //                  std::string darkest_secret);
    // void put_contact() const;
    // std::string get_first_name() const;
    // std::string get_last_name() const;
    // std::string get_nickname() const;
    // bool is_empty() const;
};

#endif