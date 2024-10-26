#ifndef ICE_HPP
#define ICE_HPP

// #include <iostream>
#include <string>

#include "AMateria.hpp"
// #include "Config.hpp"

class Ice : public AMateria {
   public:
    Ice();
    Ice(Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();

    virtual AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
