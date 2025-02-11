```mermaid
classDiagram
    class Bureaucrat {
        -const string name_
        -int grade_
        -static const int HIGHEST_GRADE
        -static const int LOWEST_GRADE
        +Bureaucrat(name: string, grade: int)
        +Bureaucrat(other: Bureaucrat)
        +operator=(other: Bureaucrat) Bureaucrat
        +~Bureaucrat()
        +getName() string
        +getGrade() int
        +incrementGrade()
        +decrementGrade()
        +signForm(form: AForm)
        +executeForm(form: AForm)
    }

    class Intern {
        +makeForm(formName: string, target: string) AForm*
        -createShrubberyCreationForm(target: string) AForm*
        -createRobotomyRequestForm(target: string) AForm*
        -createPresidentialPardonForm(target: string) AForm*
    }

    class AForm {
        <<abstract>>
        -const string name_
        -bool isSigned_
        -const int gradeRequiredToSign_
        -const int gradeRequiredToExecute_
        #static const int HIGHEST_GRADE
        #static const int LOWEST_GRADE
        +AForm(name: string, gradeToSign: int, gradeToExecute: int)
        +AForm(other: AForm)
        +operator=(other: AForm) AForm
        +~AForm()
        +getName() string
        +getIsSigned() bool
        +getGradeRequiredToSign() int
        +getGradeRequiredToExecute() int
        +beSigned(bureaucrat: Bureaucrat)
        +execute(executor: Bureaucrat) void*
        #virtual executeAction() void* 
    }

    class ShrubberyCreationForm {
        -static const int SIGN_GRADE
        -static const int EXEC_GRADE
        +ShrubberyCreationForm(target: string)
        #executeAction() void*
    }

    class RobotomyRequestForm {
        -static const int SIGN_GRADE
        -static const int EXEC_GRADE
        +RobotomyRequestForm(target: string)
        #executeAction() void*
    }

    class PresidentialPardonForm {
        -static const int SIGN_GRADE
        -static const int EXEC_GRADE
        +PresidentialPardonForm(target: string)
        #executeAction() void*
    }

    class GradeTooHighException {
        +what() char*
    }

    class GradeTooLowException {
        +what() char*
    }

    class FormNotSignedException {
        +what() char*
    }

    class FormNotFoundException {
        +what() char*
    }

    Bureaucrat ..> AForm : executes
    Intern ..> AForm : creates
    AForm <|-- ShrubberyCreationForm
    AForm <|-- RobotomyRequestForm
    AForm <|-- PresidentialPardonForm
    AForm *-- GradeTooHighException
    AForm *-- GradeTooLowException
    AForm *-- FormNotSignedException
    Intern *-- FormNotFoundException

    note for ShrubberyCreationForm "SIGN_GRADE = 145\nEXEC_GRADE = 137"
    note for RobotomyRequestForm "SIGN_GRADE = 72\nEXEC_GRADE = 45"
    note for PresidentialPardonForm "SIGN_GRADE = 25\nEXEC_GRADE = 5"
