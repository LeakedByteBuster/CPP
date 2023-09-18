#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>

class WrongAnimal
{
protected :
    std::string type;

public :
    WrongAnimal();
    WrongAnimal(const WrongAnimal &);
    WrongAnimal&    operator=(const WrongAnimal &);
    virtual ~WrongAnimal();

    void    makeSound() const;
    std::string     getType() const;
    void            setType(std::string);
};

#endif // WRONGCAT_HPP