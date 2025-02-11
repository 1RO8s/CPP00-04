#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE), target_(target) {
  std::srand(std::time(NULL));  // 乱数の初期化
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target_(other.target_) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    target_ = other.target_;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string& RobotomyRequestForm::getTarget() const { return target_; }

void* RobotomyRequestForm::executeAction() const {
  std::cout << "* drilling noises *" << std::endl;
  if (std::rand() % 2) {
    std::cout << target_ << " has been robotomized successfully!" << std::endl;
  } else {
    std::cout << "Robotomization of " << target_ << " failed." << std::endl;
  }
  return NULL;
} 