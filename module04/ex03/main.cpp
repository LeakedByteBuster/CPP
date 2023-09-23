#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

/* 
*   TODO:
*   ----
*
*   Deep Copy for Copying Charachter and  deleting equipped Materias before adding new ones
*
*   implement Use() function in Cure.cpp & Ice.cpp //\\ equi() unequip() use() ==> Character.cpp
*   
*   Could cause a leaks // To Check ||| initZero() Character.cpp
*   
*/

#ifdef TEST_LEAKS
    #include <stdlib.h>

    void    lk()
    {
        system("leaks Interface");
        return ;
    }
#endif // TEST_LEAKS


int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    /* Testing Leaks */
    #ifdef TEST_LEAKS
        atexit(lk);
    #endif // TEST_LEAKS
    return (0);
}