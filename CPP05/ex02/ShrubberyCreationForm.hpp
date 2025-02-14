#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string target_;
  static const int SIGN_GRADE = 145;
  static const int EXEC_GRADE = 137;

  virtual void* executeAction() const;

 public:
  explicit ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
  virtual ~ShrubberyCreationForm();

  const std::string& getTarget() const;
};

#endif
