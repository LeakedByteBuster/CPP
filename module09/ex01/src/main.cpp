#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2) 
            throw std::invalid_argument("Error: <./RPN> <\"...\">");

        double result = RPNcalculator(av[1]);
        std::cout << result << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
