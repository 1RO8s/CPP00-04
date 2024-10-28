#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("") {
    std::cout << "Animal(" << this->_type << ") is created" << std::endl;
    this->_brain = new Brain();
}

Animal::Animal(const Animal& other) : _type(other.getType()), _brain(new Brain(*other._brain)) {
    std::cout << "Animal(" << this->_type << ") is created by copy constructor" << std::endl; 
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->_type = other.getType();
        *this->_brain = *other._brain;
        std::cout << "copy brain in animal" << std::endl;
    }
    std::cout << "Animal(" << this->_type << "): Copy assignment" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal(" << this->_type << ") is destroyed" << std::endl;
    delete this->_brain;
}

const std::string& Animal::getType() const {
    return this->_type;
}

std::string Animal::getBrainIdea(int index) const {
    return this->_brain->getIdea(index);
}

void Animal::setBrainIdea(int index, const std::string& idea) {
    this->_brain->setIdea(index, idea);
}
