#include "iter.hpp"

#include <iostream>

template <typename T>
void print(T& value) {
  std::cout << "value: " << value << std::endl;
}

int main() {
  int intArr[] = {1, 2, 3, 4, 5};
  iter(intArr, 5, print);

  std::string strArr[] = {"Hello", "World", "42", "Tokyo", "!!"};
  iter(strArr, 5, print);

  float floatArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  iter(floatArr, 5, print);

  return 0;
}
