#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class   FragTrap : virtual public ClapTrap {

private:
    int attackDamage;
    int hitPoints;

public :
    FragTrap(std::string);
    FragTrap(const FragTrap &);
    FragTrap& operator=(const FragTrap &);
    ~FragTrap();

    /* Displays a positive high fives request on the standard output */
    void    highFivesGuys(void);
    void    attack(const std::string& target);
    int     getHitPoints() const;
    int     getAttackDamage() const;


};


#endif // FRAGTRAP_HPP
