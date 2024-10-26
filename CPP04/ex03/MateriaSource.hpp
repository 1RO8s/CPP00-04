#ifndef MATERIA_SOURCE_H
# define MATERIA_SOURCE_H

# include "IMateriaSource.hpp"
# include <string>

# define NUM_MATERIA 4

class MateriaSource : public IMateriaSource {
  public:
	  MateriaSource();
	  MateriaSource(const MateriaSource &a);
	  virtual ~MateriaSource();
	  MateriaSource &operator=(const MateriaSource &a);

	  const AMateria *getMateria(int index) const;

	  void learnMateria(AMateria *m);
	  AMateria *createMateria(std::string const &type);

  private:
	  AMateria *materia[NUM_MATERIA];
};

#endif
