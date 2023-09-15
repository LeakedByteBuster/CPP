#include <iostream>
#include "ClapTrap.hpp"

#ifdef STATS
    static void    showPlayerStats(const ClapTrap& player)
    {
        std::cout << player.getName() << "\n HP: " << player.getHitPoints()\
            << "\t EP: " << player.getEnergyPoints() << "\t AD: " << \
                player.getAttackDamage() << std::endl;
        return ;
    }
#endif // STATS

int main(void)
{
    ClapTrap    rob("\e[1;91mﺎﻳﺮﻴﻓﺎﺟ رﺎﺑﻮﻜﺳﺇ يﺩ ﻮﻠﺑﺎﺑ لﺇ تﺮﺑﻭﺭ\033[0m");
    ClapTrap    jay("\e[1;94mQuento El Pesos Del Handre\033[0m");
    #ifdef THIRD
        ClapTrap    twin(jay);
    #endif // THIRD


    #ifdef STATS
        std::cout <<
        "/* -------------------------------------------------------------------------- */\n"
        "/*                        📊 Fighters Initial Stats 📊                        */\n"
        "/* -------------------------------------------------------------------------- */\n";
        showPlayerStats(rob);
        showPlayerStats(jay);
        #ifdef THIRD
            showPlayerStats(twin);
        #endif // THIRD
        std::cout << std::endl << std::endl;
    #endif // STATS

    #ifndef NOT_SIMULATE
        std::cout <<
        "/* -------------------------------------------------------------------------- */\n"
        "/*                              🤼 Fight Starts 🤼                            */\n"
        "/* -------------------------------------------------------------------------- */\n";
    #endif // NOT_SIMULATE

    rob.setAttackDamage(5);
    rob.attack(jay.getName());
    if (rob.getHitPoints() > 0 && rob.getEnergyPoints() > 0)
        jay.takeDamage(rob.getAttackDamage());

    jay.beRepaired(3);
    
    jay.setAttackDamage(4);
    jay.attack(rob.getName());
    if (jay.getHitPoints() > 0 && jay.getEnergyPoints() > 0)
        rob.takeDamage(jay.getAttackDamage());

    rob.setAttackDamage(6);
    rob.attack(jay.getName());
    if (rob.getHitPoints() > 0 && rob.getEnergyPoints() > 0)
        jay.takeDamage(rob.getAttackDamage());
    
    rob.beRepaired(2);

    rob.setAttackDamage(7);
    rob.attack(jay.getName());
    if (rob.getHitPoints() > 0 && rob.getEnergyPoints() > 0)
        jay.takeDamage(rob.getAttackDamage());

    jay.setAttackDamage(99);
    jay.attack(rob.getName());
    if (jay.getHitPoints() > 0 && jay.getEnergyPoints() > 0)
        rob.takeDamage(jay.getAttackDamage());
    
    jay.beRepaired(3);

    rob.setAttackDamage(7);
    rob.attack(jay.getName());
    if (rob.getHitPoints() > 0 && rob.getEnergyPoints() > 0)
        jay.takeDamage(rob.getAttackDamage());

    #ifdef STATS
        std::cout << std::endl;
        std::cout <<
        "/* -------------------------------------------------------------------------- */\n"
        "/*                               🔥 Fight Ends 🔥                             */\n"
        "/* -------------------------------------------------------------------------- */\n";
        showPlayerStats(rob);
        showPlayerStats(jay);
        #ifdef THIRD
            showPlayerStats(twin);
        #endif // THIRD
        std::cout << std::endl;
    #endif // STATS

    return (0);
}
