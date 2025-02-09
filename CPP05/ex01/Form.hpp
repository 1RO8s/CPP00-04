#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
 private:
  const std::string name_;
  bool isSigned_;
  const int gradeRequiredToSign_;
  const int gradeRequiredToExecute_;
  static const int HIGHEST_GRADE = 1;
  static const int LOWEST_GRADE = 150;

 public:
  Form(const std::string& name, int gradeToSign, int gradeToExecute);
  Form(const Form& other);
  Form& operator=(const Form& other);
  ~Form();

  const std::string& getName() const;
  bool getIsSigned() const;
  int getGradeRequiredToSign() const;
  int getGradeRequiredToExecute() const;

  // Member functions
  void beSigned(const Bureaucrat& bureaucrat);

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
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif 