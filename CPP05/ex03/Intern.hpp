#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <string>

class AForm;

class Intern {
 private:
  // フォーム作成用の関数ポインタの型定義
  typedef AForm* (Intern::*FormCreator)(const std::string&) const;

  // 各フォームの作成関数
  AForm* createShrubberyCreationForm(const std::string& target) const;
  AForm* createRobotomyRequestForm(const std::string& target) const;
  AForm* createPresidentialPardonForm(const std::string& target) const;

 public:
  // Orthodox Canonical Form
  Intern();
  Intern(const Intern& other);
  Intern& operator=(const Intern& other);
  ~Intern();

  // Member functions
  AForm* makeForm(const std::string& formName, const std::string& target) const;

  // Exception class
  class FormNotFoundException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif
