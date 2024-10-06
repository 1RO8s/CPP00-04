#include "Harl.hpp"

// int main(int argc, char **argv) {
//   if (argc > 2) {
//     std::cout << "Too many arguments." << std::endl;
//     return (EXIT_FAILURE);
//   }
//   try {
//     Harl harl;
//     if (argc == 2) {
//       harl.complain(static_cast<std::string>(argv[1]));
//     } 
//     // else {
//     //   harl.complain("SSSS");
//     // }
//     return (EXIT_SUCCESS);
//   } catch (const std::exception& e) {
//     std::cout << "An error occurred." << std::endl;
//     return (EXIT_FAILURE);
//   }
// }

int main(void) {
  Harl harl;
  try {
    std::cout << "--- complain DEBUG ---" << std::endl;
    harl.complain("DEBUG");
    std::cout << "--- complain INFO ---" << std::endl;
    harl.complain("INFO");
    std::cout << "--- complain WARNING ---" << std::endl;
    harl.complain("WARNING");
    std::cout << "--- complain ERROR ---" << std::endl;
    harl.complain("ERROR");
    std::cout << "--- complain INVALID ---" << std::endl;
    harl.complain("INVALID");
    std::cout << "--- complain ---" << std::endl;
    harl.complain("");
    return (EXIT_SUCCESS);
  } catch (const std::exception& e) {
    std::cout << "An error occurred." << std::endl;
    return (EXIT_FAILURE);
  }
}