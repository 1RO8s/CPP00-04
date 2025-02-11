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
    }

    class GradeTooHighException {
        +what() char*
    }

    class GradeTooLowException {
        +what() char*
    }

    Bureaucrat *-- GradeTooHighException
    Bureaucrat *-- GradeTooLowException
    std.exception <|-- GradeTooHighException
    std.exception <|-- GradeTooLowException

    note for Bureaucrat "HIGHEST_GRADE = 1
    LOWEST_GRADE = 150"
