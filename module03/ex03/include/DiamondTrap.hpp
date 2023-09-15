#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string name;

public:
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap&);
    DiamondTrap& operator=(const DiamondTrap&);
    ~DiamondTrap();
    
    // Displays both its name and its ClapTrap name
    void whoAmI();
    void    attack(const std::string& target);
    std::string getName() const;

};


#endif // DIAMOND_HPP