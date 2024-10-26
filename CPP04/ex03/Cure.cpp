#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure(" << this->getType() << ") is created" << std::endl;
}

Cure::Cure(Cure& other) : AMateria(other.getType()) {
    std::cout << "Cure(" << this->getType() << ") is created by copy constructor" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other) {
        this->setType(other.getType());
    }
    std::cout << "Cure(" << this->getType() << "): Copy assignment" << std::endl;
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure(" << this->getType() << ") is destroyed" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
