#include <iostream>
#include <stdexcept>
#include <fstream>
#include "BitcoinExchange.hpp"

static void parseInput(std::ifstream &ifs)
{
    std::string line;
    std::getline(ifs, line);
    if (line != "date | value")
        std::cout << "Error : bad input ==> " + line << std::endl;
    while (!ifs.eof() && ifs.good()){
        std::getline(ifs, line);
        if (line.empty()){
            std::cout << "Error : bad input ==> empty line" << std::endl;
        } else {
            checkSyntax(line);
        }
    }
}

// 2012-01-11 |2147483 648
// 2012-01-11 |2147483 648
int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Error : Could not open file" << std::endl;
        return (1);
    }
    std::ifstream   ifs(av[1]);
    if (!ifs.is_open()) {
        std::cout << "Error : Could not open file" << std::endl;
        ifs.close();
        return (1);
    }
    parseInput(ifs);
    ifs.close();
    return (0);
}
