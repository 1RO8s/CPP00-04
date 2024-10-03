#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
  std::cout << this->_name << " is created" << std::endl;
}

HumanB::~HumanB() {
  std::cout << this->_name << " is destroyed" << std::endl;
}

void HumanB::attack() {
  if (this->_weapon == NULL)
    std::cout << this->_name << " can't attack without a weapon" << std::endl;
  else
    std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
  this->_weapon = &weapon;
}
