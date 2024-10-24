#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("") {
    std::cout << "WrongAnimal(" << this->_type << ") is created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other.getType()) {
    std::cout << "WrongAnimal(" << this->_type << ") is created by copy constructor" << std::endl; 
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
        this->_type = other.getType();    
    std::cout << "WrongAnimal(" << this->_type << "): Copy assignment" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal(" << this->_type << ") is destroyed" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "grr-ow" << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return this->_type;
}

void WrongAnimal::setType(const std::string& type) {
    this->_type = type;
}
