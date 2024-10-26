#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < NUM_MATERIA; ++i){
    materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& a) {
    *this = a;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < NUM_MATERIA; ++i) {
        if (materia[i]) {
            delete materia[i];
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& a) {
  for (int i = 0; i < NUM_MATERIA; ++i) {
    const AMateria* tmp = a.getMateria(i);
    if (tmp) {
      materia[i] = tmp->clone();
    } else {
      materia[i] = NULL;
    }
  }
  return *this;
}

const AMateria* MateriaSource::getMateria(int index) const {
	if (0 <= index && index < NUM_MATERIA) {
    return NULL;
  }
  return materia[index];
}

void MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < NUM_MATERIA; ++i) {
    if (!materia[i]) {
      materia[i] = m;
      break;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
  for (int i = 0; i < NUM_MATERIA; ++i) {
    if (!materia[i]) {
      break;
    }
    if (materia[i]->getType() == type) {
      return materia[i]->clone();
    }
  }
  return 0;
}
