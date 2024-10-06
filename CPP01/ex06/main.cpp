#include "Harl.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Invalid number of arguments." << std::endl;
    return (EXIT_FAILURE);
  }
  try {
    Harl harl;
    harl.complain(static_cast<std::string>(argv[1]));
    return (EXIT_SUCCESS);
  } catch (const std::exception& e) {
    std::cout << "An error occurred." << std::endl;
    return (EXIT_FAILURE);
  }
}
