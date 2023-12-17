#include "ScalarConverter.hpp"
#include "utils.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(ScalarConverter &)
{

}

ScalarConverter& ScalarConverter::operator=(ScalarConverter &)
{
    return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

void    ScalarConverter::convert(std::string input)
{
    // check if input is char
    if (input.length() == 1 && !isdigit(*input.data())){
        convertToChar(*input.data());
        return ;
    }
    // check if input is valid
    char    *endptr;
    double  res = strtod(input.data(), &endptr);
    if (input.data() == endptr){
        std::cout << "char : impossible\n" << "int : impossible\n" << 
            "float : impossible\n" << "double : impossible\n";
        return ;
    }

    if (input.find('.') != std::string::npos || res == INFINITY || res == -INFINITY || res != res){
        // check if input is double
        if (input.find('f') == std::string::npos && (res != INFINITY || res != -INFINITY)){
            convertToDouble(res);
            return ;
        }
        // if (res == INFINITY || res == -INFINITY || res != res){
            convertToFloat(input);
            // return ;
        // }
    }
    // check if input is int
    else if (isdigit(*input.data()) || atoi(input.data())){
        convertToInt(input);
        return ;
    }

}
