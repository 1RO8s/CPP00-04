#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class ClapTrap {
  public:
	  ClapTrap();
	  ClapTrap(const std::string name);
	  ClapTrap(const ClapTrap &other);
	  ClapTrap &operator=(const ClapTrap &other);
	  ~ClapTrap();

	  const std::string &getName() const;
	  void setName(const std::string &name);
	  int getHitPoints() const;
	  void setHitPoints(const int hitPoints);
	  int getEnergyPoints() const;
	  void setEnergyPoints(const int energyPoints);
	  int getAttackDamage() const;
	  void setAttackDamage(const int attackDamage);

	  void attack(const std::string &target);
	  void takeDamage(unsigned int amount);
	  void beRepaired(unsigned int amount);

  private:
	  std::string _name;
	  unsigned int _hitPoints;
	  unsigned int _energyPoints;
	  unsigned int _attackDamage;
	protected:
		bool _isActionable() const;
};

std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap);

#endif
