#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
  int N = 3;
  Zombie* zombies = zombieHorde(N, "Zombie");
  if (zombies == NULL)
    return (EXIT_FAILURE);

  for (int i = 0; i < N; i++)
    zombies[i].announce();

  delete[] zombies;
  return 0;
}