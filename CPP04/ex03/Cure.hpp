#ifndef CURE_HPP
#define CURE_HPP

// #include <iostream>
#include <string>

#include "AMateria.hpp"
// #include "Config.hpp"

class Cure : public AMateria {
   public:
    Cure();
    Cure(Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure();

    virtual AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
