#ifndef HARL_HPP
#define HARL_HPP

#include <string>

# define HBLK "\e[1;90m"
# define HRED "\e[1;91m"
# define HGRN "\e[1;92m"
# define HYEL "\e[1;93m"
# define HBLU "\e[1;94m"
# define HMAG "\e[1;95m"
# define HCYN "\e[1;96m"
# define HWHT "\e[1;97m"
# define HORG "\033[48:5:208m\033[m"
# define RESET "\x1b[0m"


class Harl {

private:

    /* Outputs a debug message */
    void    debug( void );

    /* Outputs an info message */
    void    info( void );

    /* Outputs a warning message */
    void    warning( void );

    /* Outputs an error message */
    void    error( void );

    void    messageNotFound( void );

public:
   /*  Constructor: used to initialize the array of functors*/
    Harl();

    /* Calls the corresponding function based on the given level argument */
    void    complain( std::string level );

};

/* Typedef an array of pointers to member functions */
typedef void (Harl::*HarlFuncPtr_t[5])(void);

/* Declartion of HarlFuncPtr_t array */
static  HarlFuncPtr_t func;

#endif //  HARL_HPP