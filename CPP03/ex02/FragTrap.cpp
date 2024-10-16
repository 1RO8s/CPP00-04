#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap is created" << std::endl;
	this->setHitPoints(FragTrap::MAX_HIT_POINTS);
	this->setEnergyPoints(FragTrap::MAX_ENERGY_POINTS);
	this->setAttackDamage(FragTrap::ATTACK_DAMAGE);
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	std::cout << "FragTrap(" << this->getName() << ") is created." << std::endl;
	this->setHitPoints(FragTrap::MAX_HIT_POINTS);
	this->setEnergyPoints(FragTrap::MAX_ENERGY_POINTS);
	this->setAttackDamage(FragTrap::ATTACK_DAMAGE);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap(" << this->getName() << ") is created by Copy constructor." << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap(" << this->getName() << ") is destroyed." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap(" << this->getName() << ") is Copy assignment operator called" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->getName() << " is asking for a high five!" << std::endl;
}

