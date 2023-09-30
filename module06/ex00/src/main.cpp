#include <iostream>
#include <stdexcept>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw std::runtime_error("Error: invalid number of arguments");

        ScalarConverter::convert(av[1]);
    }
    catch(const std::exception &e){
        std::cout << e.what() << std::endl;
    }

    return (0);
}