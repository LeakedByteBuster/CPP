#include <cmath> // isnan(), isinf()
#include <cstdlib> // strtod()
#include "ScalarConverter.hpp"
#include "utils.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter &rhs)
{
    if (&rhs == this)
        return ;
    *this = rhs;
}
ScalarConverter& ScalarConverter::operator=(ScalarConverter &) {return (*this);}
ScalarConverter::~ScalarConverter(){}

/* Used for better readability */
#define CHECK_INFF input.find("inff") == std::string::npos
#define CHECK_NANF input.find("nanf") == std::string::npos

void    ScalarConverter::convert(std::string input)
{
    // check if input is char
    if (input.length() == 1 && !isdigit(*input.data())){
        convertToChar(*input.data());
        return ;
    }
    // check if a conversion is possible
    char    *endptr;
    double  res = strtod(input.data(), &endptr);
    if (input.data() == endptr){
        std::cout << "char : impossible\n" << "int : impossible\n" << 
            "float : impossible\n" << "double : impossible\n";
        return ;
    }
    // check if input is double or float
    if (input.find('.') != std::string::npos || isinf(res) || isnan(res)){
        if (((isinf(res) && CHECK_INFF) || (isnan(res) && CHECK_NANF)) || 
            ((input.find('f') == std::string::npos) && CHECK_NANF && CHECK_INFF)){
            convertToDouble(input);
            return ;
        }
        convertToFloat(input);
    }
    // check if input is int
    else if (isdigit(*input.data()) || atoi(input.data())){
        convertToInt(input);
        return ;
    }

}
