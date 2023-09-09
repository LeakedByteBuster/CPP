#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap{

private :
    std::string name;
    int         hitPoints; /*  represent the health of the ClapTrap  */
    int         energyPoints;
    int         attackDamage;

public :
    ClapTrap(std::string name); /* Default Constructor */
    ClapTrap(const ClapTrap &); /* Copy Constructor */
    ClapTrap    operator=(const ClapTrap &); /* Copy Assignement Operator */
    ~ClapTrap(); /* Destructor */

    void attack(const std::string& target); /*  */
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName() const;
    int        getHitPoints() const;
    int        getEnergyPoints() const;
    int        getAttackDamage() const;
    
    void    setHitPoints(const int);
    void    setEnergyPoints(const int);
    void    setAttackDamage(const int);

};

#endif //  CLAPTRAP_HPP
