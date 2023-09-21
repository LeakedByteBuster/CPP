#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class   Animal{

protected :
    std::string type;

public :
    Animal();
    Animal(const Animal &);
    Animal&    operator=(const Animal &);
    virtual ~Animal();

    virtual std::string*        getIdeas() const;
    virtual void                makeSound() const;
    std::string                 getType() const;
    void                        setType(std::string);
};

#endif  //ANIMAL_HPP