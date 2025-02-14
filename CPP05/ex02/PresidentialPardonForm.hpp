#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string target_;
  static const int SIGN_GRADE = 25;
  static const int EXEC_GRADE = 5;

  virtual void* executeAction() const;

 public:
  explicit PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
  virtual ~PresidentialPardonForm();

  const std::string& getTarget() const;
};

#endif
