#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

public :

    Zombie(std::string name);
    ~Zombie();

    // Print "<name>: BraiiiiiiinnnzzzZ" in STDOUT
    void    announce( void );
    //  Returns name
    std::string getName() const;
    //  Set value of attribute name as the given name in function parameters
    void        setName(std::string name);

private :
    // Zombie's name
    std::string  name;
};

#endif // ZOMBIE_HPP