#include <iostream>
#include <sstream>
#include <algorithm>
#include "BitcoinExchange.hpp"

static bool isStringDigit(std::string str, size_t size)
{
    size_t i = 0;
    for (; i < size; i++)
        if (!std::isdigit(str[i]))
            break;
    return (i == size ? 1 : 0);
}

static bool isDateCorrect(std::string &s, std::string &sub)
{
    // std::cout << sub << std::endl;
    /* parse year */
    size_t  pos = sub.find('-');
    std::string year = sub.substr(0, pos);
    if (year.size() != 4 || !isStringDigit(year, 4) || (pos == std::string::npos)) {
        std::cout << "Error : bad input ==> " + s << std::endl;
        return (0);
    }
    
    /* parse month */
    size_t  pos2 = sub.find('-', pos +1);
    std::string month = sub.substr(pos + 1, (pos2 - 1 - pos));
    if (month.size() != 2 || !isStringDigit(month, 2) || (pos == std::string::npos)) {
        std::cout << "Error : bad input ==> " + s << std::endl;
        return (0);
    }

    /* parse day */
    size_t  pos3 = sub.find(' ', pos2 + 1);
    std::string date = sub.substr(pos2 + 1, pos3 - pos2);
    if ((date.size() != 3) || !isStringDigit(date, 2) || (pos == std::string::npos)) {
        std::cout << "Error : bad input ==> " + s << std::endl;
        return (0);
    }

    return (0);
}

static bool isValueCorrect(std::string &s, std::string &sub)
{
    std::cout << "sub == " << sub << std::endl;
    size_t n = std::count(sub.begin(), sub.end(), '.');
    // size_t n2 = std::count(sub.begin(), sub.end(), ' ');
    // size_t n3 = std::count(sub.begin(), sub.end(), '.');
    if ((n > 1) || (sub[0] != ' ')) {
        std::cout << "Error : bad input ==> " + s << std::endl;
        return (0);
    }

    char    *endptr;
    double  d = strtod(sub.data(), &endptr);
    (void)d;
    if (endptr == sub.data()){
        std::cout << "Error : bad input ==> " + s << std::endl;
    }
    return (0);
}


bool    checkSyntax(std::string &s)
{
    /* Check numbers of '|' and space ' ' */
    size_t  n = std::count(s.begin(), s.end(), '|');
    size_t n2 = std::count(s.begin(), s.end(), ' ');
    if ((n != 1) || (n2 != 2)) {
        std::cout << "Error : bad input '|' or '-' ==> " + s << std::endl;
    } else {
        size_t  pos = s.find('|');
        std::string date = s.substr(0, pos);
        /* Check numbers of '-' in substring "date"*/
        n = std::count(date.begin(), date.end(), '-');
        if (n != 2){
            std::cout << "Error : bad input ' ' ==> " + s << std::endl;
            return (0);
        }
        /* Check date format */
        isDateCorrect(s, date);

        std::string value = s.substr(pos +1, std::string::npos);
        // std::cout << "value == " << value << std::endl;
        isValueCorrect(s, value);
    }
    return (0);
}

void    storeInput()
{

}