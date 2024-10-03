#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
    std::cout << name << " is created" << std::endl;
}

HumanA::~HumanA() {
    std::cout << this->_name << " is destroyed" << std::endl;
}

void HumanA::attack() {
    std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
}
