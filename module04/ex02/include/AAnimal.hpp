#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class   AAnimal{

protected :
    std::string type;

public :
    AAnimal();
    AAnimal(const AAnimal &);
    AAnimal&    operator=(const AAnimal &);
    virtual ~AAnimal();

    /* Returns a pointer to a string "NOT TO AN ARRAY OF STRINGS"*/
    virtual std::string*        getIdeas() const = 0;
    virtual void                makeSound() const = 0;
    std::string                 getType() const;
    void                        setType(std::string);
};

#endif  //AANIMAL_HPP