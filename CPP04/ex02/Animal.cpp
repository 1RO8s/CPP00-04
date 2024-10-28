#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("") {
    std::cout << "Animal(" << this->_type << ") is created" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other.getType()) {
    std::cout << "Animal(" << this->_type << ") is created by copy constructor" << std::endl; 
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->_type = other.getType();
        std::cout << "copy brain in animal" << std::endl;
    }
    std::cout << "Animal(" << this->_type << "): Copy assignment" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal(" << this->_type << ") is destroyed" << std::endl;
}

const std::string& Animal::getType() const {
    return this->_type;
}
