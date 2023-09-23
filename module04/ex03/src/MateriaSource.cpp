#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp" /* for INVENTORY_CAPACITY Macro*/

/* Frees AMaterias in MateriaSource's inventory */
static void    freeAMateriasEquipped(AMateria **ptr)
{
    for (int i = 0; i < INVENTORY_CAPACITY; i++){
        if (ptr[i] != NULL)
            delete ptr[i];
            ptr[i] = NULL;
    }
    return ;
}

/* init AMateria pointers attributes to NULL */
static void initZero(AMateria **p)
{
    for (int i = 0; i < INVENTORY_CAPACITY; i++){
        p[i] = NULL;
    }
    return ;
}

MateriaSource::MateriaSource()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "MateriaSource default constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG
    
    initZero(storedAMateria);
}

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "MateriaSource copy constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    initZero(storedAMateria);
    *this = rhs;
}

MateriaSource&  MateriaSource::operator=(const MateriaSource &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "MateriaSource copy constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG
    
    AMateria            **l = this->storedAMateria;
    const AMateria      **r = (const AMateria **)rhs.storedAMateria;
    
    freeAMateriasEquipped(storedAMateria);
    for (int i = 0; i < INVENTORY_CAPACITY; i++){
        if (r[i] != NULL)
            l[i] = r[i]->clone();
    }

    return (*this);
}

MateriaSource::~MateriaSource()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "MateriaSource destructor constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    freeAMateriasEquipped(storedAMateria);
}

void    MateriaSource::learnMateria(AMateria*  materia)
{
    if (materia != NULL){
        for (int i = 0; i < INVENTORY_CAPACITY; i++){
            if (storedAMateria[i] == NULL){
                storedAMateria[i] = materia;
                return ;
            }
        }
        delete materia;
    }
    return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < INVENTORY_CAPACITY; i++){
        if (storedAMateria[i] != NULL && storedAMateria[i]->getType() == type){
            return (storedAMateria[i]->clone());
        }
    }
    return (0);
}
