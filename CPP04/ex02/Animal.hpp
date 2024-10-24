#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include "Brain.hpp"

class Animal {
   public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    virtual void makeSound() const = 0;

    const std::string& getType() const;
    void setType(const std::string& type);
    std::string getBrainIdea(int index) const;
    void setBrainIdea(int index, const std::string& idea);

    protected:
    std::string _type;
    private:
        Brain* _brain;
};

#endif
