#include "BitcoinExchange.hpp"



int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw std::invalid_argument("Error: not enough parameter");
        
        BitcoinExchange bex(av[1]);


        // std::cout << std::fixed << std::setprecision(2) << bex.getDb().lower_bound("2009-03-07")->first;

    } catch(std::exception  &e) {
        std::cout << e.what() << std::endl;
        return (1);
    }
    return (0);
}
