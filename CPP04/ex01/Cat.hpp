#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        virtual ~Cat();

        void makeSound() const;

        std::string getBrainIdea(int index) const;
        void setBrainIdea(int index, const std::string& idea);
        
    private:
        Brain* _brain;
};

#endif
