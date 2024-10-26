#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
   public:
    AMateria();
    AMateria(std::string const& type);
    AMateria(AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();

    std::string const& getType() const;
    void setType(const std::string type);

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

   protected:
    std::string _type;
};

#endif
