#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
  public:
	  DiamondTrap();
	  DiamondTrap(const std::string name);
	  DiamondTrap(const DiamondTrap &other);
	  DiamondTrap &operator=(const DiamondTrap &other);
	  ~DiamondTrap();

		void whoAmI();
		
	private:
    std::string _name;
};

#endif
