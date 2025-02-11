#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target_(other.target_) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    target_ = other.target_;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string& ShrubberyCreationForm::getTarget() const { return target_; }

void* ShrubberyCreationForm::executeAction() const {
  std::string filename = target_ + "_shrubbery";
  std::ofstream ofs(filename.c_str());
  if (!ofs) {
    std::cerr << "Error: Could not create file " << filename << std::endl;
    return NULL;
  }

  // ASCII art tree
  ofs << "       _-_" << std::endl;
  ofs << "    /~~   ~~\\" << std::endl;
  ofs << " /~~         ~~\\" << std::endl;
  ofs << "{               }" << std::endl;
  ofs << " \\  _-     -_  /" << std::endl;
  ofs << "   ~  \\\\ //  ~" << std::endl;
  ofs << "_- -   | | _- _" << std::endl;
  ofs << "  _ -  | |   -_" << std::endl;
  ofs << "      // \\\\" << std::endl;

  ofs.close();
  return NULL;
}
