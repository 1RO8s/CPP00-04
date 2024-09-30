/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:55:57 by hnagasak          #+#    #+#             */
/*   Updated: 2024/09/30 20:42:14 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {
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
};

#endif