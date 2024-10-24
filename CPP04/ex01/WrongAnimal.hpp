#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal {
   public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();

    virtual void makeSound() const;

    const std::string& getType() const;
    void setType(const std::string& type);

   protected:
    std::string _type;
};

#endif
