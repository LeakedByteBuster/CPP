#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class   Dog : public AAnimal{
private :
    Brain   *ideas;

public :
    Dog();
    Dog(const Dog &);
    Dog&    operator=(const Dog &);
    virtual ~Dog();

    void            makeSound() const;
    /* Returns a pointer TO AN ARRAY OF STRINGS Brain::getIdeas*/
    std::string*    getIdeas() const;

};

#endif  //DOG_HPP