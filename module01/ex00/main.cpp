#include "Zombie.hpp"
#include "utils.hpp"

/*
    TODO: Add delete to the destructor
*/
int main()
{
    Zombie *z = newZombie(giveMeName());
    delete z;
    randomChump(giveMeName());

    #ifdef LOOP
        for (int i; i < 100; i++){
            Zombie *z = newZombie(giveMeName());
            delete z;
            randomChump(giveMeName());
        }
    #endif //LOOP
    return (0);
}