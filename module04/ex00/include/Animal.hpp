#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include <string>

class   Animal{

protected :
    std::string type;

public :
    Animal();
    Animal(const Animal &);
    Animal&    operator=(const Animal &);
    virtual ~Animal();

    virtual void    makeSound() const;
    std::string     getType() const;
    void            setType(std::string);
};

#endif  //ANIMAL_HPP