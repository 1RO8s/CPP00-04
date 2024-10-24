#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    this->setType("Cat");
    std::cout << "Cat(" << this->_type << ") is created" << std::endl;
}

Cat::Cat(const Cat& other) {
    this->setType(other.getType());
    std::cout << "Cat(" << this->_type << ") is created by copy constructor" << std::endl; 
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        // this->_type = other.getType();
        Animal::operator=(other);
    }
    std::cout << "Cat(" << this->_type << "): Copy assignment" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat(" << this->_type << ") is destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "meow" << std::endl;
}
