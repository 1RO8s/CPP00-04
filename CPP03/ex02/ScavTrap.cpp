#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap is created" << std::endl;
	this->setHitPoints(ScavTrap::MAX_HIT_POINTS);
	this->setEnergyPoints(ScavTrap::MAX_ENERGY_POINTS);
	this->setAttackDamage(ScavTrap::ATTACK_DAMAGE);
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap(" << this->getName() << ") is created." << std::endl;
	this->setHitPoints(ScavTrap::MAX_HIT_POINTS);
	this->setEnergyPoints(ScavTrap::MAX_ENERGY_POINTS);
	this->setAttackDamage(ScavTrap::ATTACK_DAMAGE);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap(" << this->getName() << ") is created by Copy constructor." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap(" << this->getName() << ") is destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap(" << this->getName() << ") is Copy assignment operator called" << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string &target) {
	if (this->_isActionable()) {
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	} else {
		std::cout << "ScavTrap " << this->getName() << " has no energy and cannot attack!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode." << std::endl;
}
