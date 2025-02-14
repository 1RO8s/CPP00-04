#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  std::string target_;
  static const int SIGN_GRADE = 72;
  static const int EXEC_GRADE = 45;
  
  virtual void* executeAction() const;

 public:
  explicit RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm& other);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
  virtual ~RobotomyRequestForm();

  const std::string& getTarget() const;
};

#endif
