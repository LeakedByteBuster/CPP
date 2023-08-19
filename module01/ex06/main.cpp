#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
    /* Check number of arguments */
    if (ac != 2)
    {
        std::cerr << HRED << "Error: invalid number of arguments: ./Harl <warning level>\n" \
            << RESET;
        return (1);
    }

    Harl        msg;
    std::string input;

    input = av[1];
    /* execute corresponding function  */
    msg.complain(input);

    return (0);
}