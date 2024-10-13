#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap is created" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap(" << this->_name << ") is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other.getName()),
    _hitPoints(other.getHitPoints()), _energyPoints(other.getEnergyPoints()),
	_attackDamage(other.getAttackDamage())
{
	std::cout << "ClapTrap(" << this->_name << ") is created by Copy constructor." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	std::cout << "ClapTrap(" << this->_name << ") is Copy assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap(" << this->_name << ") is destroyed." << std::endl;
}

bool ClapTrap::_isActionable() const {
	return (this->_energyPoints > 0 && this->_hitPoints > 0);
}

void ClapTrap::attack(const std::string &target) {
	if (this->_isActionable()) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		--this->_energyPoints;
	} else {
		std::cout << "ClapTrap " << this->_name << " has no energy and cannot attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int damage) {
	if (this->_isActionable()) {
		std::cout << "ClapTrap " << this->_name << " takes " << damage << " points of damage! Ouch!" << std::endl;
		if (damage > this->_hitPoints)
			this->_hitPoints = 0;
		else
			this->_hitPoints -= damage;
	} else {
		std::cout << "ClapTrap " << this->_name << " has no energy and cannot takeDamage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int repairPoints) {
	if (this->_isActionable()) {
		std::cout << "ClapTrap " << this->_name << " repaired itself for " << repairPoints << " hit points! Feeling better!" << std::endl;
		this->_energyPoints--;
			this->_hitPoints += repairPoints;
	} else {
		std::cout << "ClapTrap " << this->_name << " has no energy and cannot be repaired!" << std::endl;
	}
}

const std::string &ClapTrap::getName() const {
	return (this->_name);
}

void ClapTrap::setName(const std::string &name) {
	this->_name = name;
}

int ClapTrap::getHitPoints() const {
	return (this->_hitPoints);
}

void ClapTrap::setHitPoints(const int hitPoints) {
	this->_hitPoints = hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return (this->_energyPoints);
}

void ClapTrap::setEnergyPoints(const int energyPoints) {
	this->_energyPoints = energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return (this->_attackDamage);
}

void ClapTrap::setAttackDamage(const int attackDamage) {
	this->_attackDamage = attackDamage;
}

std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap) {
	os << "name: " << clapTrap.getName() <<
		",hitPoints: " << clapTrap.getHitPoints() <<
		",energyPoints: " << clapTrap.getEnergyPoints() << 
		",attackDamage: " << clapTrap.getAttackDamage();
	return (os);
}
