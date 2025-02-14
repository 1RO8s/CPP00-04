#include "Bureaucrat.hpp"

#include <iostream>

#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name) {
  if (grade < HIGHEST_GRADE) {
    throw Bureaucrat::GradeTooHighException();
  }
  if (grade > LOWEST_GRADE) {
    throw Bureaucrat::GradeTooLowException();
  }
  grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name_(other.name_), grade_(other.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    grade_ = other.grade_;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::incrementGrade() {
  if (grade_ <= HIGHEST_GRADE) {
    throw Bureaucrat::GradeTooHighException();
  }
  --grade_;
}

void Bureaucrat::decrementGrade() {
  if (grade_ >= LOWEST_GRADE) {
    throw Bureaucrat::GradeTooLowException();
  }
  ++grade_;
}

void Bureaucrat::signForm(AForm& form) {
  try {
    form.beSigned(*this);
    std::cout << name_ << " signed " << form.getName() << std::endl;
  } catch (const AForm::GradeTooLowException& e) {
    std::cout << name_ << " couldn't sign " << form.getName()
              << " because grade is too low" << std::endl;
  }
}

void Bureaucrat::executeForm(const AForm& form) const {
  try {
    form.execute(*this);
    std::cout << name_ << " executed " << form.getName() << std::endl;
  } catch (const std::exception& e) {
    std::cout << name_ << " couldn't execute " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
