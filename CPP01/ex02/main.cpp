#include <iostream>
#include <string>
#include <iomanip>

int main() {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << std::setw(10) << std::left << "&str" << ":" << &str << std::endl;
  std::cout << std::setw(10) << std::left << "stringPTR" << ":" << stringPTR << std::endl;
  std::cout << std::setw(10) << std::left << "&stringREF" << ":" << &stringREF << std::endl;

  std::cout << std::setw(10) << std::left << "str" << ":" << str << std::endl;
  std::cout << std::setw(10) << std::left << "*stringPTR" << ":" << *stringPTR << std::endl;
  std::cout << std::setw(10) << std::left << "stringREF" << ":" << stringREF << std::endl;
  return 0;
}
