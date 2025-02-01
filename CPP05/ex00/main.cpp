#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  try {
    // 正常な作成テスト
    std::cout << "=== Constructor Test (Normal) ===" << std::endl;
    Bureaucrat normal("Normal", 75);
    std::cout << normal << std::endl;

    // 昇進テスト　正常系
    std::cout << "\n=== Increment Test (Normal) ===" << std::endl;
    Bureaucrat high("High", 2);
    std::cout << "Before: " << high << std::endl;
    high.incrementGrade();
    std::cout << "After:  " << high << std::endl;

    // 降格テスト　正常系
    std::cout << "\n=== Decrement Test (Normal) ===" << std::endl;
    Bureaucrat low("Low", 149);
    std::cout << "Before: " << low << std::endl;
    low.decrementGrade();
    std::cout << "After:  " << low << std::endl;

    // コンストラクタ例外テスト - 等級が高すぎる
    std::cout << "\n=== Too high exception test on constructor ==="
              << std::endl;
    try {
      Bureaucrat tooHigh("TooHigh", 0);
    } catch (const Bureaucrat::GradeTooHighException& e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // コンストラクタ例外テスト - 等級が低すぎる
    std::cout << "\n=== Too low exception test on constructor ===" << std::endl;
    try {
      Bureaucrat tooLow("TooLow", 151);
    } catch (const Bureaucrat::GradeTooLowException& e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // 昇進による例外テスト
    std::cout << "\n=== Increment Exception Test ===" << std::endl;
    try {
      Bureaucrat highest("Highest", 1);
      std::cout << highest << std::endl;
      highest.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException& e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // 降格による例外テスト
    std::cout << "\n=== Decrement Exception Test ===" << std::endl;
    try {
      Bureaucrat lowest("Lowest", 150);
      std::cout << lowest << std::endl;
      lowest.decrementGrade();
    } catch (const Bureaucrat::GradeTooLowException& e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }

  } catch (const std::exception& e) {
    std::cout << "Unexpected exception: " << e.what() << std::endl;
  }

  return 0;
}
