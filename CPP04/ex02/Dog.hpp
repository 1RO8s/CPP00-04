#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal{
	public:
	  Dog();
	  Dog(const Dog &other);
	  Dog &operator=(const Dog &other);
	  virtual ~Dog();

	  void makeSound() const;

		std::string getBrainIdea(int index) const;
    void setBrainIdea(int index, const std::string& idea);
        
  private:
    Brain* _brain;
};

#endif
