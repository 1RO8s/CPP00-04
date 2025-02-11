#include "AForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name_(name),
      isSigned_(false),
      gradeRequiredToSign_(gradeToSign),
      gradeRequiredToExecute_(gradeToExecute) {
  if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE) {
    throw AForm::GradeTooHighException();
  }
  if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE) {
    throw AForm::GradeTooLowException();
  }
}

AForm::AForm(const AForm& other)
    : name_(other.name_),
      isSigned_(other.isSigned_),
      gradeRequiredToSign_(other.gradeRequiredToSign_),
      gradeRequiredToExecute_(other.gradeRequiredToExecute_) {}

AForm& AForm::operator=(const AForm& other) {
  if (this != &other) {
    isSigned_ = other.isSigned_;
    // const メンバは代入できないのでスキップ
  }
  return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return name_; }

bool AForm::getIsSigned() const { return isSigned_; }

int AForm::getGradeRequiredToSign() const { return gradeRequiredToSign_; }

int AForm::getGradeRequiredToExecute() const { return gradeRequiredToExecute_; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > gradeRequiredToSign_) {
    throw AForm::GradeTooLowException();
  }
  isSigned_ = true;
}

void AForm::execute(const Bureaucrat& executor) const {
  if (!isSigned_) {
    throw AForm::FormNotSignedException();
  }
  if (executor.getGrade() > gradeRequiredToExecute_) {
    throw AForm::GradeTooLowException();
  }
  executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
  os << "Form " << form.getName() << ":" << std::endl
     << "Status: " << (form.getIsSigned() ? "signed" : "not signed") << std::endl
     << "Grade required to sign: " << form.getGradeRequiredToSign() << std::endl
     << "Grade required to execute: " << form.getGradeRequiredToExecute();
  return os;
}
