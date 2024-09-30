/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 01:54:40 by hnagasak          #+#    #+#             */
/*   Updated: 2024/09/30 20:48:23 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>

std::string to_upper(std::string src) {
    std::string result;
    for (std::size_t i = 0; i < src.size(); i++) {
        result += std::toupper(src[i]);
    }
    return result;
}

void putstr(std::string str) {
    std::cout << str;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        putstr("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
        std::cout << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        putstr(to_upper(argv[i]));
    }
    std::cout << std::endl;
    return 0;
}
