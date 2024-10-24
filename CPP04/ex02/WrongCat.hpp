#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <string>
#include "Animal.hpp"

class WrongCat: public Animal {
   public:
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    virtual ~WrongCat();

    void makeSound() const;
   protected:
    // const std::string TYPE = "WrongCat";
};

#endif
