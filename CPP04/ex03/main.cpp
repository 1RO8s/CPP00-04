#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void info(const std::string &str) {
    std::cout << "\033[3;36m" << str << "\033[0m" << std::endl;
}

int main () {
  MateriaSource src = MateriaSource();
  src.learnMateria(new Ice());
  src.learnMateria(new Cure());

  // ICharacter* me = new Character("me");

  // AMateria* tmp;
  // tmp = src->createMateria("ice");
  // me->equip(tmp);
  // tmp = src->createMateria("cure");
  // me->equip(tmp);

  // ICharacter* bob = new Character("bob");
    
  // me->use(0, *bob);
  // me->use(1, *bob);


  info("--- Copy constructor and assignation operator test ---");

  MateriaSource copiedSrc(src);
  MateriaSource assignedSrc = src;

  info("## Copy constructor test");

  copiedSrc.learnMateria(new Ice());
  assignedSrc.learnMateria(new Cure());
    
  // delete bob;
  // delete me;
  // delete src;


    
  return 0;
}
