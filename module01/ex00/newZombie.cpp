#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie  *babyZombie;
    try
    {
        babyZombie = new Zombie(name);
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << "Error: allocation failed" << e.what() << "\n";
    }
    return (babyZombie);
}
