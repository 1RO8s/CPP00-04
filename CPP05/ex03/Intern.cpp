#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const {
  return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const {
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName,
                        const std::string& target) const {
  static const struct {
    const char* name;
    FormCreator creator;
  } formCreators[] = {
      {"shrubbery creation", &Intern::createShrubberyCreationForm},
      {"robotomy request", &Intern::createRobotomyRequestForm},
      {"presidential pardon", &Intern::createPresidentialPardonForm},
  };

  for (size_t i = 0; i < sizeof(formCreators) / sizeof(formCreators[0]); ++i) {
    if (formName == formCreators[i].name) {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*formCreators[i].creator)(target);
    }
  }

  throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
  return "Form type not found";
}
