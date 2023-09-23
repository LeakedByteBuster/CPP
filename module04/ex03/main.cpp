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
    #if !defined(ASSIGN)
        IMateriaSource* src = new MateriaSource();
    #else
        IMateriaSource* sr = new MateriaSource();
        IMateriaSource* src = new MateriaSource((const MateriaSource &)*sr);
    #endif // ASSIGN

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    #if defined(TESTS)
        /* Learning more than the possible capacity INVENTORY_CAPACITY*/
        src->learnMateria(new Cure());
        src->learnMateria(new Cure()); /* Reached Max */
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());
    #endif // TESTS

    #if !defined(ASSIGN) 
        ICharacter* me = new Character("me");
    #else
        ICharacter* m = new Character("me");
        ICharacter* me = new Character((const Character &)*m);
    #endif // ASSIGN
    
    AMateria* tmp;
    tmp = src->createMateria("ice"); /*  USED in TESTS  */
    me->equip(tmp);
    tmp = src->createMateria("cure"); /*  USED in TESTS  */
    me->equip(tmp);
    #if defined(TESTS)
        tmp = src->createMateria("ice"); /*  USED in TESTS  */
        me->equip(tmp);
        tmp = src->createMateria("ice");
        me->equip(tmp);
        me->unequip(3); /* Removing last equip */
        delete tmp; /* delete pointer to equip */
        tmp = src->createMateria("cure"); /* Reached Max && USED in TESTS*/
        me->equip(tmp);
        tmp = src->createMateria("ice"); /* extra item */
        me->equip(tmp);
        tmp = src->createMateria("ice"); /* extra item */
        me->equip(tmp);

        me->unequip(4); /* Testing Unequip() ==> out of range */
    #endif // TESTS

    /* Use AMateria in Inventory against 'Character' bob */
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    #if defined(TESTS)
        me->use(2, *bob);
        me->use(3, *bob);
    #endif // TESTS

    /* Frees pointers */
    delete bob;
    #if defined(ASSIGN)
        delete m;
        delete sr;
    #endif // ASSIGN
    delete me;
    delete src;

    /* Testing Leaks */
    #if defined(TEST_LEAKS)
        atexit(lk);
    #endif // TEST_LEAKS
    return (0);
}