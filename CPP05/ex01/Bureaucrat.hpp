#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

class Form;

class Bureaucrat {
 private:
  const std::string name_;
  int grade_;
  static const int HIGHEST_GRADE = 1;
  static const int LOWEST_GRADE = 150;

 public:
  // Orthodox Canonical Form
  Bureaucrat(const std::string& name, int grade);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other);
  ~Bureaucrat();

  // Getters
  const std::string& getName() const;
  int getGrade() const;

  // Grade manipulation
  void incrementGrade();
  void decrementGrade();

  // Form related
  void signForm(Form& form);

  // Exception classes
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

// Stream operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
