#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
  for (int i = 0; i < MAX_IDEAS; i++) {
    this->setIdea(i, "");
  }
  std::cout << "Brain is created" << std::endl;
}

Brain::Brain(const Brain& other) {
  for (int i = 0; i < MAX_IDEAS; i++) {
    this->setIdea(i, other.getIdea(i));
  }
  std::cout << "Brain is created by copy constructor" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
  std::cout << "## Brain: Copy assignment" << std::endl;
  if (this != &other) {
    for (int i = 0; i < MAX_IDEAS; i++) {
      this->setIdea(i, other.getIdea(i));
    }
  }
  std::cout << "Brain: Copy assignment" << std::endl;
  return *this;
}

Brain::~Brain() {
  std::cout << "Brain is destroyed" << std::endl;
}

std::string Brain::getIdea(int index) const {
  return this->_ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
  this->_ideas[index] = idea;
}
