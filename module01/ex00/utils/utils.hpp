#ifndef UTILS_HPP
#define UTILS_HPP

// Returns a name for the zombie created
std::string	giveMeName( void );
//  Creates a zombie, name it, and return it
Zombie*		newZombie( std::string name );
//  Creates a zombie, name it, and the zombie announces itself.
void		randomChump( std::string name );

#endif // UTILS_HPP