#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class   HumanA{

private:
    std::string name;
    Weapon      &weapon;


public:
    
    HumanA(std::string name, Weapon &weapon);
    // name's attribute getter and setter
    std::string getName() const;
    void        setName(std::string name);

    // Prints "<name> attacks with their <weapon type>" in STDOUT
    void        attack();
    // Sets Weapon
    void    setWeapon(Weapon &weapon);
    Weapon  &getWeapon() const;
};

#endif // HUMANA_HPP