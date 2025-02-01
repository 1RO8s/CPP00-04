#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name) {
  if (grade < this->HIGHEST_GRADE) throw GradeTooHighException();
  if (grade > this->LOWEST_GRADE) throw GradeTooLowException();
  this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name_(other.name_), grade_(other.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    // name_はconstなのでコピーできない
    this->grade_ = other.grade_;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return this->name_; }

int Bureaucrat::getGrade() const { return this->grade_; }

void Bureaucrat::incrementGrade() {
  if (this->grade_ <= this->HIGHEST_GRADE) throw GradeTooHighException();
  --this->grade_;
}

void Bureaucrat::decrementGrade() {
  if (this->grade_ >= this->LOWEST_GRADE) throw GradeTooLowException();
  ++this->grade_;
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
