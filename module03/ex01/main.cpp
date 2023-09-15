#include <iostream>
#include "ScavTrap.hpp"

#ifdef STATS
    static void    showPlayerStats(const ClapTrap& clap)
    {
        std::cout << clap.getName() << "\n HP: " << clap.getHitPoints()\
            << "\t EP: " << clap.getEnergyPoints() << "\t AD: " << \
                clap.getAttackDamage() << std::endl;
        return ;
    }

    static void    showPlayerStats(const ScavTrap& scav)
    {
        std::cout << scav.getName() << "\n HP: " << scav.getHitPoints()\
            << "\t EP: " << scav.getEnergyPoints() << "\t AD: " << \
                scav.getAttackDamage() << std::endl;
        return ;
    }

    static void showRobotCharacteristic(ClapTrap &a, ClapTrap &b, ScavTrap &c, ScavTrap &d)
    {
        showPlayerStats(a);
        showPlayerStats(b);
        showPlayerStats(c);
        showPlayerStats(d);

        std::cout << std::endl << std::endl;
        return ;
    }
#endif // STATS

#ifndef NOT_SIMULATE
    /* ClapRobot "a" causes "n" damage to ClapRobot "b" */
    static inline void    attackRobot(ClapTrap &a, ClapTrap &b)
    {
        a.attack(b.getName());
        if (a.getHitPoints() > 0 && a.getEnergyPoints() > 0)
            b.takeDamage(a.getAttackDamage());
        return ;
    }

    /* ScavRobot "a" causes "n" damage to ScavRobot "b" */
    static inline void    attackRobot(ScavTrap &a, ScavTrap &b)
    {
        a.attack(b.getName());
        if (a.getHitPoints() > 0 && a.getEnergyPoints() > 0)
            b.takeDamage(a.getAttackDamage());
        return ;
    }

    /* ScavRobot "a" causes "n" damage to ClapRobot "b" */
    static inline void    attackRobot(ScavTrap &a, ClapTrap &b)
    {
        a.attack(b.getName());
        if (a.getHitPoints() > 0 && a.getEnergyPoints() > 0)
            b.takeDamage(a.getAttackDamage());
        return ;
    }

    /* ClapRobot "a" causes "n" damage to ScavRobot "b" */
    static inline void    attackRobot(ClapTrap &a, ScavTrap &b)
    {
        a.attack(b.getName());
        if (a.getHitPoints() > 0 && a.getEnergyPoints() > 0)
            b.takeDamage(a.getAttackDamage());
        return ;
    }

    /* Simulates a fight between robots */
    static inline void    simulateTheFight(ClapTrap& clap1, ClapTrap& clap2
        , ScavTrap &scav1, ScavTrap &scav2)
    {
        std::cout <<
        "/* -------------------------------------------------------------------------- */\n"
        "/*                              🤼 Fight Starts 🤼                            */\n"
        "/* -------------------------------------------------------------------------- */\n";

        scav2.guardGate();
        attackRobot(clap2, clap1);

        attackRobot(scav2, clap1);
        attackRobot(scav1, clap1);

        attackRobot(clap2, scav1);
        clap2.beRepaired(5);
        
        scav1.guardGate();
        
        attackRobot(scav1, clap2);

        attackRobot(scav1, scav2);
        attackRobot(scav2, scav1);
        scav2.beRepaired(10);

        attackRobot(scav1, scav2);
        scav2.guardGate();
        attackRobot(scav2, scav1);
        attackRobot(scav2, scav1);
        attackRobot(scav2, scav1);
        attackRobot(scav2, scav1);
        attackRobot(scav2, scav1);

        return ;
    }
#endif // NOT_SIMULATE

int main(void)
{
    ClapTrap    clap1("\e[1;91mClap1\033[0m");
    ScavTrap    scav1("\e[1;93mScav1\033[0m");
    #ifdef ASSIGN
        ClapTrap    clap2(clap1);
        ScavTrap    scav2(scav1);
    #else
        ClapTrap    clap2("\e[1;92mClap2\033[0m");
        ScavTrap    scav2("\e[1;94mScav2\033[0m");
    #endif // THIRD

    std::cout << std::endl;

    #ifdef STATS
        #ifdef TEST_HEALTH
            scav2.setHitPoints(0);
            scav1.setHitPoints(0);
            clap1.setHitPoints(0);
            clap2.setHitPoints(0);
        #elif TEST_ENERGY
            clap1.setEnergyPoints(0);
            clap2.setEnergyPoints(0);
            scav2.setEnergyPoints(0);
            scav1.setEnergyPoints(0);
        #endif // DEATH
        std::cout <<
        "\n/* -------------------------------------------------------------------------- */\n"
        "/*                        📊 Fighters Initial Stats 📊                        */\n"
        "/* -------------------------------------------------------------------------- */\n";
        
        showRobotCharacteristic(clap1, clap2, scav1, scav2);
    #endif // STATS

    #ifndef NOT_SIMULATE
        simulateTheFight(clap1, clap2, scav1, scav2);
    #endif // NOT_SIMULATE

    #ifdef STATS
        std::cout <<
        "\n/* -------------------------------------------------------------------------- */\n"
        "/*                               🔥 Fight Ends 🔥                             */\n"
        "/* -------------------------------------------------------------------------- */\n";

        showRobotCharacteristic(clap1, clap2, scav1, scav2);
    #endif // STATS

    return (0);
}
