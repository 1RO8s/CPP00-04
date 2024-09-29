#include "Zombie.hpp"

#include <cstdlib>

Zombie* zombieHorde(int N, std::string name) {
  if (N <= 0) {
    return NULL;
  }

  Zombie* zombies;
  try {
    zombies = new Zombie[N];
  } catch (std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (int i = 0; i < N; i++)
    zombies[i].setName(name);
  return zombies;
}
