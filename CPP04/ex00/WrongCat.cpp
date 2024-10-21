#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
    this->setType("WrongCat");
    std::cout << "WrongCat(" << this->_type << ") is created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    this->setType(other.getType());
    std::cout << "WrongCat(" << this->_type << ") is created by copy constructor" << std::endl; 
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        this->_type = other.getType();
    }
    std::cout << "WrongCat(" << this->_type << "): Copy assignment" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat(" << this->_type << ") is destroyed" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "meow" << std::endl;
}
