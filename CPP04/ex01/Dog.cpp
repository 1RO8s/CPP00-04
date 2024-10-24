#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    this->setType("Dog");
    std::cout << "Dog(" << this->_type << ") is created" << std::endl;
}

Dog::Dog(const Dog& other) {
    this->setType(other.getType());
    std::cout << "Dog(" << this->_type << ") is created by copy constructor" << std::endl; 
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->_type = other.getType();
        Animal::operator=(other);
    }
    std::cout << "Dog(" << this->_type << "): Copy assignment" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog(" << this->_type << ") is destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "bow-wow!" << std::endl;
}