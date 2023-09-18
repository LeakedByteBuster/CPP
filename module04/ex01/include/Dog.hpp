#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Dog : public Animal{
private :
    Brain   *ideas;

public :
    Dog();
    Dog(const Dog &);
    Dog&    operator=(const Dog &);
    virtual ~Dog();

    void            makeSound() const;
    std::string*    getIdeas() const;

};

#endif  //DOG_HPP