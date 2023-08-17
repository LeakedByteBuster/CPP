#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class   HumanB {

private:
    Weapon      *weapon;
    std::string name;

public:

    // Constructor  
    HumanB(std::string name);

    // name's attribute getter and setter
    std::string getName() const;
    void        setName(std::string name);

    // Prints "<name> attacks with their <weapon type>" in STDOUT
    void        attack();
    // Sets Weapon
    void        setWeapon(Weapon &weapon);
    Weapon      *getWeapon() const;
};

#endif // HUMANB_HPP