#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/* -------------------------------------------------------------------------- */
/*                                   Utils                                    */
/* -------------------------------------------------------------------------- */

/* Frees AMaterias in character's inventory */
static void    freeAMateriaEquipped(AMateria **ptr)
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

/* Performs a deep copy for *matEquipped[] attribute */
static void    deepCopy(Character &lhs , const Character &rhs)
{
    /* Copying AMateria equipped */
    const AMateria    **l = lhs.getMatEquipped();
    const AMateria    **r = rhs.getMatEquipped();

    if (r != NULL){
        for (int i = 0; i < INVENTORY_CAPACITY; i++){
            if (r[i] != NULL)
                l[i] = r[i]->clone();
        }
    }
    return ;
}

/* -------------------------------------------------------------------------- */
/*           Constructors & Destructor & Copy Assignement Operator            */
/* -------------------------------------------------------------------------- */

Character::Character() : name(""), capacity(0)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Character default constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    /* Empty inventory */
    initZero(matEquipped);
}

Character::Character(std::string name) : name(name), capacity(0)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Character parameterized constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    /* Empty inventory */
    initZero(matEquipped);
}

Character::Character(Character const &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Character copy constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    /* Could cause a leaks // To Check */
    initZero(matEquipped);
    *this = rhs;
}

Character&  Character::operator=(Character const &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Character copy assignement operator is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    if (this == &rhs)
        return (*this);

    /* copy name */
    this->name = rhs.getName();
    /* Free before copying new AMaterias */
    freeAMateriaEquipped(matEquipped);
    /* Performs a deep copy for *matEquipped[] attribute */
    deepCopy(*this, rhs);

    return (*this);
}

Character::~Character()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Character destructor constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    freeAMateriaEquipped(matEquipped);
}

/* ------------------------------------------------------------------------- */
/*                                  Methods                                  */
/* ------------------------------------------------------------------------- */

/* Each Character can equip up to INVENTORY_CAPACITY AMateria */
void    Character::equip(AMateria* mat)
{
    /* Checking if inventory is full */
    if (capacity > INVENTORY_CAPACITY)
        return ;
    /* looking for the first empty slot in inventory */
    int i = 0;
    while (i < INVENTORY_CAPACITY)
    {
        if (matEquipped[i] == NULL)
            break;
        i++;
    }
    /* Equipping the AMateria */
    matEquipped[i] = mat;
    /* + 1 item in inventory */
    capacity++;

    return ;
}

/* the caller is responsible for freeing the item after calling unequip() */
void    Character::unequip(int i)
{
    /* Checking if i to unequip is a valid one */
    if ((i >= 0 && i < 4) && (matEquipped[i] != NULL)){
            matEquipped[i] = NULL;
            capacity--; /* One slot is available */
    }
    return ;
}

/* Use AMateria equipped at index i on "ICharacter" target */
void    Character::use(int i, ICharacter& target)
{
    /* Checking if the requested AMateria is equipped */
    if ((i >= 0 && i < INVENTORY_CAPACITY) && (matEquipped[i] != NULL)){
            matEquipped[i]->AMateria::use(target);
    }
    return ;
}

/* -------------------------------------------------------------------------- */
/*                             Setters && Getters                             */
/* -------------------------------------------------------------------------- */
void    Character::setName(const std::string &name)
{
    this->name = name;
    return ;
}

AMateria const      Character::**getMatEquipped() const
{
    return (matEquipped);
}

std::string const & Character::getName() const
{
    return (name);
}
