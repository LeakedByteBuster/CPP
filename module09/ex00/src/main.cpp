#include "BitcoinExchange.hpp"



int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw std::invalid_argument("Error: not enough parameter");

        BitcoinExchange bex(av[1]);
        bex.readInputFile();

    } catch(std::exception  &e) {
        std::cout << e.what() << std::endl;
        return (1);
    }
    return (0);
}
