#include "whatever.hpp"

#include <iostream>

template <typename T>
void test_template(std::string type, T a, T b) {
  // Tの型名を表示
  std::cout << "Type: " << type << std::endl;
  std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
  ::swap(a, b);
  std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
  std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
  std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
  std::cout << "----------------------------------------" << std::endl;
}

int main() {
  test_template("int", 2, 3);
  test_template("float", 2.5f, 3.5f);
  test_template("double", 2.5, 3.5);
  test_template("char", 'a', 'b');
  test_template("string", "hello", "world");
  return 0;
}
