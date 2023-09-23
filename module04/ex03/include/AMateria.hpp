#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string mType;

public:
    AMateria(); /* Default Constructor */
    AMateria(std::string const & type); /* Parameterized Constructor */
    AMateria(AMateria const & rhs); /* Copy Constructor */
    AMateria&    operator=(AMateria const & rhs); /* Copy assignement operator */
    virtual ~AMateria(); /* Destructor */

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0; // return a new instance of the same type
    virtual void use(ICharacter& target); // prints on stdout

    std::ostream&   operator<<(std::ostream& os);
};

#endif // AMATERIA_HPP