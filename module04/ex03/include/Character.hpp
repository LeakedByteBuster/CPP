#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class   AMateria;

#define INVENTORY_CAPACITY 4

class Character : public ICharacter {

private:
    std::string name;   /* name of the character */
    AMateria    *matEquipped[4]; /* represent AMateria inventory of the character */
    int         capacity; /* number of items in charachter's inventory */

public:
    Character();
    Character(std::string name);
    Character(Character const &);
    Character&  operator=(Character const &);
    ~Character();

    std::string const & getName() const;
    AMateria          **getMatEquipped() const;
    void                setName(const std::string &);
    void                equip(AMateria* m);
    void                unequip(int idx);
    void                use(int idx, ICharacter& target);
};

#endif  // CHARACTER_HPP
