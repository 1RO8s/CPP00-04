#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: 引数が正しくありません。使用法: ./RPN \"逆ポーランド記法の式\"" << std::endl;
        return 1;
    }

    RPN calculator;
    try {
        int result = calculator.evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
} 
