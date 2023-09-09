#include <iostream>
#include "ClapTrap.hpp"
int main(void)
{
    ClapTrap    rob("Robert El Pablo Del Escobare");
    ClapTrap    jay("Quento El Pesos Del Handre");

    rob.attack(jay.getName());
    jay.beRepaired(11);

    jay.setAttackDamage(11);
    jay.attack(rob.getName());
    rob.takeDamage(jay.getAttackDamage());

    return (0);
}
