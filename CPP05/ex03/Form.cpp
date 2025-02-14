#include "Form.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name_(name),
      isSigned_(false),
      gradeRequiredToSign_(gradeToSign),
      gradeRequiredToExecute_(gradeToExecute) {
  if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE) {
    throw Form::GradeTooHighException();
  }
  if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(const Form& other)
    : name_(other.name_),
      isSigned_(other.isSigned_),
      gradeRequiredToSign_(other.gradeRequiredToSign_),
      gradeRequiredToExecute_(other.gradeRequiredToExecute_) {}

Form& Form::operator=(const Form& other) {
  if (this != &other) {
    isSigned_ = other.isSigned_;
  }
  return *this;
}

Form::~Form() {}

const std::string& Form::getName() const { return name_; }

bool Form::getIsSigned() const { return isSigned_; }

int Form::getGradeRequiredToSign() const { return gradeRequiredToSign_; }

int Form::getGradeRequiredToExecute() const { return gradeRequiredToExecute_; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > gradeRequiredToSign_) {
    throw Form::GradeTooLowException();
  }
  isSigned_ = true;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  os << "Form " << form.getName() << ":" << std::endl
     << "Status: " << (form.getIsSigned() ? "signed" : "not signed") << std::endl
     << "Grade required to sign: " << form.getGradeRequiredToSign() << std::endl
     << "Grade required to execute: " << form.getGradeRequiredToExecute();
  return os;
} 