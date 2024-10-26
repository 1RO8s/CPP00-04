#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("cure") {
    std::cout << "Ice(" << this->getType() << ") is created" << std::endl;
}

Ice::Ice(Ice& other) : AMateria(other.getType()) {
    std::cout << "Ice(" << this->getType() << ") is created by copy constructor" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
        this->setType(other.getType());
    }
    std::cout << "Ice(" << this->getType() << "): Copy assignment" << std::endl;
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice(" << this->getType() << ") is destroyed" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice();
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
