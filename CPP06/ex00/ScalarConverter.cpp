#include "ScalarConverter.hpp"

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  (void)other;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    // 文字列がfloatリテラルかどうかをチェック
    bool isFloat = literal.length() > 0 && literal[literal.length() - 1] == 'f';

    // 特殊値の処理
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    try {
        // 文字列リテラル（'a'）の処理
        if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
            char c = literal[1];
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
            return;
        }

        // 単一文字（a）の処理
        if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
            std::cout << "char: '" << literal[0] << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
            std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
            return;
        }

        // 数値の処理
        std::string numStr = literal;
        if (isFloat) {
            // 末尾のfを削除
            numStr = literal.substr(0, literal.length() - 1);
        }
        
        double value = std::atof(numStr.c_str());

        // char
        if (value < 0 || value > 127) {
            std::cout << "char: impossible" << std::endl;
        } else if (!std::isprint(static_cast<int>(value))) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        }

        // int
        if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        }

        // float
        if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::lowest()) {
            std::cout << "float: impossible" << std::endl;
        } else {
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
        }

        // double
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;

    } catch (const std::exception& e) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
