#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public :
    WrongCat();
    WrongCat(const WrongCat &);
    WrongCat&    operator=(const WrongCat &);
    virtual ~WrongCat();

    void    makeSound() const;
};

#endif // WRONGANIMAL_HPP