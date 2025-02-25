#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base() {}

Base* generate(void) {
  Base* base = NULL;
  std::srand(std::time(NULL));
  int random = std::rand() % 3;

  if (random == 0) base = new A();
  if (random == 1) base = new B();
  if (random == 2) base = new C();
  std::cout << "Generated class as Base* pointer" << std::endl; 
  return base;
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) std::cout << "This is pointer of A class" << std::endl;
  if (dynamic_cast<B*>(p)) std::cout << "This is pointer of B class" << std::endl;
  if (dynamic_cast<C*>(p)) std::cout << "This is pointer of C class" << std::endl;
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "This is reference of A class" << std::endl;
  } catch (std::exception& e) {}
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "This is reference of B class" << std::endl;
  } catch (std::exception& e) {}
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "This is reference of C class" << std::endl;
  } catch (std::exception& e) {}
}
