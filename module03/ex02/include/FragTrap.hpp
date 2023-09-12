#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class   FragTrap : public ClapTrap {

public :
    FragTrap(std::string);
    FragTrap(const FragTrap &);
    FragTrap& operator=(const FragTrap &);
    ~FragTrap();

    /* Displays a positive high fives request on the standard output */
    void    highFivesGuys(void);
};


#endif // FRAGTRAP_HPP
