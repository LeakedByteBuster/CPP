#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#ifdef STATS
    /* types of objects */
    #define TYPES_OF_ROBOTS_LIST \
        ROBOT(ClapTrap) \
        ROBOT(ScavTrap) \
        ROBOT(FragTrap)
        
    /* Prints the robot characteristics : Name, Damage, Energy, HitPoint */
    #define ROBOT(type) \
        static void    showPlayerStats(const type& robot) \
        { \
            std::cout << robot.getName() << "\n HP: " << robot.getHitPoints()\
                << "\t EP: " << robot.getEnergyPoints() << "\t AD: " << \
                    robot.getAttackDamage() << std::endl; \
            return ; \
        }

        TYPES_OF_ROBOTS_LIST
    #undef ROBOT // Undefining ROBOT for later use

    /* Prints all characteristics for each robots */
    static void showRobotCharacteristic(ClapTrap &a, ClapTrap &b, ScavTrap &c, \
        ScavTrap &d, FragTrap& e, FragTrap &f)
    {
        showPlayerStats(a);
        showPlayerStats(b);
        showPlayerStats(c);
        showPlayerStats(d);
        showPlayerStats(e);
        showPlayerStats(f);

        std::cout << std::endl << std::endl;
        return ;
    }
#endif // STATS

#ifndef NOT_SIMULATE
    /* different combination of attacks to be made */
    #define ATTACKS_LIST \
        ROBOT(ClapTrap &a, ClapTrap &b) \
        ROBOT(ScavTrap &a, ScavTrap &b) \
        ROBOT(FragTrap &a, FragTrap &b) \
        \
        ROBOT(ClapTrap &a, ScavTrap &b) \
        ROBOT(ScavTrap &a, ClapTrap &b) \
        ROBOT(FragTrap &a, ScavTrap &b)

    /* Robot "name1" causes "attackDamage" amount to Robot "name2" */
    #define ROBOT(name1, name2) \
    \
        static inline void    attackRobot(name1, name2) \
        { \
            a.attack(b.getName()); \
            if (a.getHitPoints() > 0 && a.getEnergyPoints() > 0) \
                b.takeDamage(a.getAttackDamage()); \
            return ; \
        }

        ATTACKS_LIST 
    #undef ROBOT 

    /* Simulates a fight between robots */
    static inline void    simulateTheFight(ClapTrap& clap1, ClapTrap& clap2
        , ScavTrap &scav1, ScavTrap &scav2, FragTrap &frag1, FragTrap &frag2)
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

        attackRobot(scav1, clap2);

        attackRobot(frag1, frag2);
        attackRobot(frag2, frag1);
        frag1.highFivesGuys();
        attackRobot(frag2, frag1);
        attackRobot(frag1, scav2);

        attackRobot(scav1, scav2);
        attackRobot(scav2, scav1);
        scav2.beRepaired(10);

        attackRobot(scav1, scav2);
        scav2.guardGate();

        attackRobot(frag2, frag1);
        attackRobot(frag2, frag1);
        frag2.highFivesGuys();

        attackRobot(scav2, scav1);
        attackRobot(scav2, scav1);
        attackRobot(scav2, scav1);
        attackRobot(scav2, scav1);

        attackRobot(frag2, scav2);
        attackRobot(frag2, scav2);

        return ;
    }
#endif // NOT_SIMULATE

int main(void)
{
    ClapTrap    clap1("\e[1;91mClap1\033[0m");
    ScavTrap    scav1("\e[1;93mScav1\033[0m");
    FragTrap    frag1("\e[1;95mFrag1\033[0m");
    #ifdef ASSIGN
        ClapTrap    clap2(clap1);
        ScavTrap    scav2(scav1);
        FragTrap    frag2(frag1);

    #else
        ClapTrap    clap2("\e[1;92mClap2\033[0m");
        ScavTrap    scav2("\e[1;94mScav2\033[0m");
        FragTrap    frag2("\e[1;96mFrag2\033[0m");
    #endif // ASSIGN
    
    std::cout << std::endl;
    
    #ifdef STATS

        #ifdef TEST_HEALTH
            scav1.setHitPoints(0);
            scav2.setHitPoints(0);
            clap1.setHitPoints(0);
            clap2.setHitPoints(0);
            frag1.setHitPoints(0);
            frag2.setHitPoints(0);
        #elif TEST_ENERGY
            clap1.setEnergyPoints(0);
            clap2.setEnergyPoints(0);
            scav1.setEnergyPoints(0);
            scav2.setEnergyPoints(0);
            frag1.setEnergyPoints(0);
            frag2.setEnergyPoints(0);
        #endif // DEATH

        std::cout <<
        "\n/* -------------------------------------------------------------------------- */\n"
        "/*                        📊 Fighters Initial Stats 📊                        */\n"
        "/* -------------------------------------------------------------------------- */\n";
        
        showRobotCharacteristic(clap1, clap2, scav1, scav2, frag1, frag2);
    #endif // STATS

    #ifndef NOT_SIMULATE
        simulateTheFight(clap1, clap2, scav1, scav2, frag1, frag2);

        #ifdef STATS
            std::cout <<
            "\n/* -------------------------------------------------------------------------- */\n"
            "/*                               🔥 Fight Ends 🔥                             */\n"
            "/* -------------------------------------------------------------------------- */\n";

            showRobotCharacteristic(clap1, clap2, scav1, scav2, frag1, frag2);
        #endif // STATS
    #endif // NOT_SIMULATE


    return (0);
}
