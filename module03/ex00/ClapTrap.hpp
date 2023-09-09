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

/* -------------------------------------------------------------------------- */
/*                               Orthodox Form                                */
/* -------------------------------------------------------------------------- */
    ClapTrap(std::string name); /* Default Constructor */
    ClapTrap(const ClapTrap &); /* Copy Constructor */
    ClapTrap&    operator=(const ClapTrap &); /* Copy Assignement Operator */
    ~ClapTrap(); /* Destructor */

/* -------------------------------------------------------------------------- */
/*                                  Methods                                   */
/* -------------------------------------------------------------------------- */
    /* target loses <attack damage> hit points, Attacking costs 1 energy */
    void attack(const std::string& target);
    /* The player loses <amount> hitPoints */
    void takeDamage(unsigned int amount);
    /* Gets <amount> hit points back, repairing costs 1 energy point each. */
    void beRepaired(unsigned int amount);

/* -------------------------------------------------------------------------- */
/*                                  Getters                                   */
/* -------------------------------------------------------------------------- */
    /* Method used to get name private attribute */
    std::string getName() const;
    /* Method used to get hitPoints private attribute */
    int        getHitPoints() const;
    /* Method used to get energyPoints private attribute */
    int        getEnergyPoints() const;
    /* Method used to get attackDamage private attribute */
    int        getAttackDamage() const;

/* -------------------------------------------------------------------------- */
/*                                  Setters                                   */
/* -------------------------------------------------------------------------- */
    /* Method used to set HitPoints private attribute */
    void    setHitPoints(const int);
    /* Method used to set energyPoints private attribute */
    void    setEnergyPoints(const int);
    /* Method used to set attackDamage private attribute */
    void    setAttackDamage(const int); 

};

#endif //  CLAPTRAP_HPP
