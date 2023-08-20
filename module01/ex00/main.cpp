#include "Zombie.hpp"
#include "utils.hpp"

int main()
{
    Zombie *z = newZombie(giveMeName());
    delete z;
    randomChump(giveMeName());

    #ifdef LOOP
        for (int i = 0; i < 100; i++){
            /* it creates a zombie, name it, and return it */
            Zombie *z = newZombie(giveMeName());
            delete z;
            /* It creates a zombie, name it, and the zombie announces itself. */
            randomChump(giveMeName());
        }
    #endif //LOOP

    return (0);
}