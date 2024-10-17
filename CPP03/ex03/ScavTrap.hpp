#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap {
  public:
	  ScavTrap();
	  ScavTrap(const std::string name);
	  ScavTrap(const ScavTrap &other);
	  ~ScavTrap();
	  ScavTrap &operator=(const ScavTrap &other);

	  void attack(const std::string &target);
	  void guardGate();
	
	private:
		static const int MAX_HIT_POINTS = 100;
		static const int MAX_ENERGY_POINTS = 50;
		static const int ATTACK_DAMAGE = 20;
};

#endif
