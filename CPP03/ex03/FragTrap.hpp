#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap {
  public:
	  FragTrap();
	  FragTrap(const std::string name);
	  FragTrap(const FragTrap &other);
	  FragTrap &operator=(const FragTrap &other);
	  ~FragTrap();

		void highFivesGuys(void);
		
		static const int MAX_HIT_POINTS = 100;
		static const int MAX_ENERGY_POINTS = 100;
		static const int ATTACK_DAMAGE = 30;
};

#endif
