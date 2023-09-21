#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class   Cat : public AAnimal{
private :
    Brain   *ideas;

public :
    Cat();
    Cat(const Cat &);
    Cat&    operator=(const Cat &);
    virtual ~Cat();

    void                makeSound() const;
    /* Returns a pointer TO AN ARRAY OF STRINGS Brain::getIdeas */
    std::string*        getIdeas() const;

};

#endif  //CAT_HPP