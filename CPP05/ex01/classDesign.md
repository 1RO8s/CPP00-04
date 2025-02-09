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
        +signForm(form: Form)
    }

    class Form {
        -const string name_
        -bool isSigned_
        -const int gradeRequiredToSign_
        -const int gradeRequiredToExecute_
        -static const int HIGHEST_GRADE
        -static const int LOWEST_GRADE
        +Form(name: string, gradeToSign: int, gradeToExecute: int)
        +Form(other: Form)
        +operator=(other: Form) Form
        +~Form()
        +getName() string
        +getIsSigned() bool
        +getGradeRequiredToSign() int
        +getGradeRequiredToExecute() int
        +beSigned(bureaucrat: Bureaucrat)
    }

    class GradeTooHighException {
        +what() char*
    }

    class GradeTooLowException {
        +what() char*
    }

    Bureaucrat *-- GradeTooHighException
    Bureaucrat *-- GradeTooLowException
    Form *-- GradeTooHighException
    Form *-- GradeTooLowException
    std.exception <|-- GradeTooHighException
    std.exception <|-- GradeTooLowException
    Bureaucrat ..> Form : signs

    note for Form "HIGHEST_GRADE = 1\nLOWEST_GRADE = 150"
