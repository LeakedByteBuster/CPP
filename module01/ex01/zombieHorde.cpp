#include "Zombie.hpp"

// Allocate N zombies and returns a pointer to the first one
Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *zombieLand;
    try
    {
        zombieLand = new Zombie[N];
        for (int i = 0; i < N; i++){
            zombieLand[i].setName(name);
        }
    }

    catch (const std::bad_alloc &e)
    {
        std::cout << "Allocation Failed" << "\n";
        exit(2);
    }
    return (zombieLand);
}
