#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include <iostream>
# include <string>

# define NUM_MATERIA 4

class Character : public ICharacter {
  public:
	Character();
	Character(const std::string &name);
	Character(const Character &a);
	~Character();
  Character &operator=(const Character &a);

	std::string const &getName() const;
	const AMateria *getMateria(int index) const;

	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

  private:
	std::string name;
	AMateria *materia[NUM_MATERIA];
	bool checkIndex(int index) const;
};

#endif
