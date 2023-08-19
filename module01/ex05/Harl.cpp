#include <iostream>
#include "Harl.hpp"


void    Harl::debug( void )
{
    std::cout << HGRN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle" \
        << "-specialketchup burger. I really do!\n" << RESET;

    return ;
}

void    Harl::info( void )
{
    std::cout << HYEL << "I cannot believe adding extra bacon costs more money. You didn\'t"
        << " put enough bacon in my burger! If you did, I wouldn\'t be asking for more!\n" << RESET;

    return ;
}

void    Harl::warning( void )
{
    std::cout << HORG << "I think I deserve to have some extra bacon for free. I\'ve been "
        << "coming for years whereas you started working here since last month.\n" << RESET;
    return ;
}

void    Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
    return ;
}

void    Harl::messageNotFound( void )
{
    std::cout << "Probably complaining about\n";
    return ;
}

void    Harl::complain( std::string level )
{
    /* Determing which string we got as an input using the branchless method */
    int x =   \
                (level == "debug")    * 1
            +   (level == "info")     * 2 \
            +   (level == "warning")  * 3 \
            +   (level == "error")    * 4;

    switch (x)
    {
        /* Calls Debug function */
        case 1:
            (this->*func[1])();
            break;

        /* Calls Info function */
        case 2:
            (this->*func[2])();
            break;

        /* Calls Warning function */
        case 3:
            (this->*func[3])();
            break;
        
        /* Calls Error function */
        case 4:
            (this->*func[4])();
            break;

        default:
            std::cout << "Level: <" << level << ">: not found\n";
            break;
    }

    return ;
}

/* Initialization of " HarlFuncPtr_t func " array */
Harl::Harl()
{
    func[0] = &Harl::messageNotFound;
    func[1] = &Harl::debug;
    func[2] = &Harl::info;
    func[3] = &Harl::warning;
    func[4] = &Harl::error;
    return ;
}