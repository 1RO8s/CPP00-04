#include "Weapon.hpp"

Weapon::Weapon() {
    std::cout << "Weapon object created" << std::endl;
}

Weapon::Weapon(std::string type) : _type(type) {
    std::cout << type << " Weapon is created" << std::endl;
}

Weapon::~Weapon() {
    std::cout << this->_type << " Weapon is destroyed" << std::endl;
}

const std::string& Weapon::getType() const {
    return this->_type;
}

void Weapon::setType(std::string type) {
    this->_type = type;
}
