#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), _name("") {
  std::cout << "DiamondTrap is created" << std::endl;
  this->setHitPoints(FragTrap::MAX_HIT_POINTS);
  this->setEnergyPoints(ScavTrap::MAX_ENERGY_POINTS);
  this->setAttackDamage(FragTrap::ATTACK_DAMAGE);
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
  std::cout << "DiamondTrap(" << this->getName() << ") is created." << std::endl;
  this->setHitPoints(FragTrap::MAX_HIT_POINTS);
  this->setEnergyPoints(ScavTrap::MAX_ENERGY_POINTS);
  this->setAttackDamage(FragTrap::ATTACK_DAMAGE);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other) {
  std::cout << "DiamondTrap(" << this->getName() << ") is created by Copy constructor." << std::endl;
  this->setHitPoints(other.getHitPoints());
  this->setEnergyPoints(other.getEnergyPoints());
  this->setAttackDamage(other.getAttackDamage());
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap(" << this->getName() << ") is destroyed." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  if (this != &other) {
    ClapTrap::operator=(other);
  }
  std::cout << "DiamondTrap(" << this->getName() << ") is Copy assignment operator called" << std::endl;
  return (*this);
}

void DiamondTrap::whoAmI() {
  std::cout << "I am " << this->_name << " and my ClapTrap name is " << this->getName() << std::endl;
}
