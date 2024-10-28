#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    this->_type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog(" << this->_type << ") is created" << std::endl;
}

Dog::Dog(const Dog& other) {
    this->_type = other.getType();
    std::cout << "Dog(" << this->_type << ") is created by copy constructor" << std::endl; 
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        *this->_brain = *other._brain;
    }
    std::cout << "Dog(" << this->_type << "): Copy assignment" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog(" << this->_type << ") is destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "bow-wow!" << std::endl;
}

std::string Dog::getBrainIdea(int index) const {
    return this->_brain->getIdea(index);
}

void Dog::setBrainIdea(int index, const std::string& idea) {
    this->_brain->setIdea(index, idea);
}
