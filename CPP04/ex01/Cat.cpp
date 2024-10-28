#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat(" << this->_type << ") is created" << std::endl;
}

Cat::Cat(const Cat& other): _brain(new Brain(*other._brain)) {
    this->_type = other.getType();
    std::cout << "Cat(" << this->_type << ") is created by copy constructor" << std::endl; 
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        *this->_brain = *other._brain;
    }
    std::cout << "Cat(" << this->_type << "): Copy assignment" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat(" << this->_type << ") is destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "meow" << std::endl;
}

std::string Cat::getBrainIdea(int index) const {
    return this->_brain->getIdea(index);
}

void Cat::setBrainIdea(int index, const std::string& idea) {
    this->_brain->setIdea(index, idea);
}
