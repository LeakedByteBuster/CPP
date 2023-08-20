#include "Zombie.hpp"
#include "utils.hpp"

int main()
{
    int N = 10;
    Zombie *z = zombieHorde(N, giveMeName());
    for (int i = 0; i < N; i++){
        z[i].announce();
    }
    delete[] z;
    return (0);
}