#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("void") {
    std::cout << "AMateria(" << this->_type << ") is created" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type) {
    std::cout << "AMateria(" << this->_type << ") is created" << std::endl;
}

AMateria::AMateria(AMateria& other) : _type(other.getType()) {
    std::cout << "AMateria(" << this->_type << ") is created by copy constructor" << std::endl; 
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        this->_type = other.getType();
    }
    std::cout << "AMateria(" << this->_type << "): Copy assignment" << std::endl;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria(" << this->_type << ") is destroyed" << std::endl;
}

std::string const& AMateria::getType() const {
    return this->_type;
}

void AMateria::setType(const std::string type) {
    this->_type = type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses " << this->getType() << " on " << target.getName() << " *" << std::endl;
}
