#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class   MateriaSource : public IMateriaSource {
private:
    AMateria    *storedAMateria[4];

public :
    
    MateriaSource();
    MateriaSource(const MateriaSource &rhs);
    MateriaSource&  operator=(const MateriaSource &rhs);
    ~MateriaSource();

    void learnMateria(AMateria*); /*  Copies AMateria passed an stores it  */
    AMateria* createMateria(std::string const & type); /* Returns a new AMateria */
};

#endif // MATERIASOURCE_HPP