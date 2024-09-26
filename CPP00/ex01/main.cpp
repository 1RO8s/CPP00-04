/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:59:19 by hnagasak          #+#    #+#             */
/*   Updated: 2024/09/26 19:14:34 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"


std::string inputCommand() {
    std::string command;
    std::cout << "Enter the command (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, command);
    return command;
}

int main() {
    PhoneBook phoneBook;
    std::string command;
    while (true) {
        command = inputCommand();
        if (command == "ADD") {
            phoneBook.add();
        } else if (command== "SEARCH") {
            phoneBook.search();
        } else if (command == "EXIT") {
            phoneBook.exit();
            break;
        } else {
            std::cout << "Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}