#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

/*
*
*       - Always prefer refrences over pointers
*       - References must be initialized at declaration
*           - member initializer list
*           - Syntax: ClassName::ClassName(parameters) : parameter1(value1), \
*               parameter(value2)... (e.g. HumanA.cpp)
*
*       - Use pointers when needed (Like case of jim below), because must explicitly \
*           initialize the reference member 'weapon' at time of declation
*
*/

int main()
{
    //  *   both weapon variables cannot be passed by value
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    return (0);
}