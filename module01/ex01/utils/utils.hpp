#ifndef UTILS_HPP
#define UTILS_HPP


// Returns a name for the zombie created
std::string	giveMeName( void );
//  Creates N zombies, name them, and return a pointer to the first one
Zombie* zombieHorde( int N, std::string name );


#endif // UTILS_HPP