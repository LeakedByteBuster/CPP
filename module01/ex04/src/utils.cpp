#include <fstream>
#include <string>
#include <iostream>

#include "SedForLosers.hpp"

void    copyAndReplace(SedForLosers &input, std::ifstream &ifs, std::ofstream &ofs)
{
    std::string str;
    std::getline(ifs, str, '\0');

    size_t  pos = 0;
    if (!str.empty()){
        while (true) {
            pos = str.find(input.getOldStr(), input.getOldStr().length() + pos);
            if (pos == std::string::npos)
                break ;

            str.erase(str.begin() + pos, str.begin() + input.getOldStr().length() + pos);
            str.insert(pos, input.getNewStr());

        }
        ofs << str;
    }

    return ;
}
