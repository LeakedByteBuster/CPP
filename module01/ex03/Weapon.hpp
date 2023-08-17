#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon{

private:
    std::string type;

public:
    // Parameterized constructor
    Weapon(std::string type);
    // Returns a const reference to type
    void        setType(std::string type);
    // Sets type using the new one passed as parameter
    std::string getType() const;
};

#endif // WEAPON_HPP