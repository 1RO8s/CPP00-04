#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

// 色のための定数
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"

// テスト結果出力用の関数
void printTestResult(const std::string& testName, bool success) {
  std::cout << (success ? BLUE : RED)
            << "[ " << (success ? "OK" : "KO") << " ] "
            << testName
            << RESET << std::endl;
}

void testFormConstruction() {
  std::cout << "\n=== Form Construction Tests ===" << std::endl;
  try {
    Form validForm("Valid Form", 100, 100);
    std::cout << validForm << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    Form invalidForm("Too High Grade", 0, 100);  // Should throw
    std::cout << invalidForm << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    Form invalidForm("Too Low Grade", 151, 100);  // Should throw
    std::cout << invalidForm << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

void testFormSigning() {
  std::cout << "\n=== Form Signing Tests ===" << std::endl;
  Form form("Important Form", 50, 30);
  Bureaucrat highGrade("High Grade Bob", 1);
  Bureaucrat mediumGrade("Medium Grade Jim", 50);
  Bureaucrat lowGrade("Low Grade Joe", 150);

  std::cout << "\nInitial state:" << std::endl;
  std::cout << form << std::endl;

  std::cout << "\nTrying to sign with low grade:" << std::endl;
  lowGrade.signForm(form);

  std::cout << "\nTrying to sign with exact required grade:" << std::endl;
  mediumGrade.signForm(form);

  std::cout << "\nTrying to sign already signed form with high grade:" << std::endl;
  highGrade.signForm(form);

  std::cout << "\nFinal state:" << std::endl;
  std::cout << form << std::endl;
}

void testFormCopy() {
  std::cout << "\n=== Form Copy Tests ===" << std::endl;
  Form original("Original Form", 75, 50);
  Bureaucrat bureaucrat("Bob", 70);

  std::cout << "Original form:" << std::endl;
  std::cout << original << std::endl;

  Form copy = original;
  std::cout << "\nCopied form:" << std::endl;
  std::cout << copy << std::endl;

  bureaucrat.signForm(copy);
  std::cout << "\nAfter signing copy:" << std::endl;
  std::cout << "Original: " << std::endl << original << std::endl;
  std::cout << "Copy: " << std::endl << copy << std::endl;
}

int main() {
  try {
    std::cout << "=== Constructor Test (Normal) ===" << std::endl;
    try {
      Bureaucrat normal("Normal", 75);
      std::cout << normal << std::endl;
      printTestResult("Normal constructor test", true);
    } catch (const std::exception& e) {
      std::cout << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
      printTestResult("Normal constructor test", false);
    }

    // 昇進テスト　正常系
    std::cout << "\n=== Increment Test (Normal) ===" << std::endl;
    try {
      Bureaucrat high("High", 2);
      std::cout << "Before: " << high << std::endl;
      high.incrementGrade();
      std::cout << "After:  " << high << std::endl;
      printTestResult("Increment test", high.getGrade() == 1);
    } catch (const std::exception& e) {
      std::cout << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
      printTestResult("Increment test", false);
    }

    // 降格テスト　正常系
    std::cout << "\n=== Decrement Test (Normal) ===" << std::endl;
    try {
      Bureaucrat low("Low", 149);
      std::cout << "Before: " << low << std::endl;
      low.decrementGrade();
      std::cout << "After:  " << low << std::endl;
      printTestResult("Decrement test", low.getGrade() == 150);
    } catch (const std::exception& e) {
      std::cout << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
      printTestResult("Decrement test", false);
    }

    // コンストラクタ例外テスト - 等級が高すぎる
    std::cout << "\n=== Too high exception test on constructor ===" << std::endl;
    bool caughtHighException = false;
    try {
      Bureaucrat tooHigh("TooHigh", 0);
    } catch (const Bureaucrat::GradeTooHighException& e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
      caughtHighException = true;
    }
    printTestResult("Too high grade exception test", caughtHighException);

    // コンストラクタ例外テスト - 等級が低すぎる
    std::cout << "\n=== Too low exception test on constructor ===" << std::endl;
    bool caughtLowException = false;
    try {
      Bureaucrat tooLow("TooLow", 151);
    } catch (const Bureaucrat::GradeTooLowException& e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
      caughtLowException = true;
    }
    printTestResult("Too low grade exception test", caughtLowException);

    // 昇進による例外テスト
    std::cout << "\n=== Increment Exception Test ===" << std::endl;
    bool caughtIncrementException = false;
    try {
      Bureaucrat highest("Highest", 1);
      std::cout << highest << std::endl;
      highest.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException& e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
      caughtIncrementException = true;
    }
    printTestResult("Increment exception test", caughtIncrementException);

    // 降格による例外テスト
    std::cout << "\n=== Decrement Exception Test ===" << std::endl;
    bool caughtDecrementException = false;
    try {
      Bureaucrat lowest("Lowest", 150);
      std::cout << lowest << std::endl;
      lowest.decrementGrade();
    } catch (const Bureaucrat::GradeTooLowException& e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
      caughtDecrementException = true;
    }
    printTestResult("Decrement exception test", caughtDecrementException);

    testFormConstruction();
    testFormSigning();
    testFormCopy();

  } catch (const std::exception& e) {
    std::cout << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    return 1;
  }

  return 0;
}
