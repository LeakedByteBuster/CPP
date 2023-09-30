#include <iostream>
#include "ScalarConverter.hpp"
#include "utils.hpp"


ScalarConverter::ScalarConverter()
{
    #if defined(DEBUG)
        std::cout << "ScalarConverter constructor is called" << std::endl;
    #endif  // DEBUG
}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{
    #if defined(DEBUG)
        std::cout << "ScalarConverter copy constructor is called" << std::endl;
    #endif  // DEBUG
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &)
{
    #if defined(DEBUG)
        std::cout << "ScalarConverter copy assignment operator is called" << std::endl;
    #endif  // DEBUG

    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    #if defined(DEBUG)
        std::cout << "ScalarConverter destructor is called" << std::endl;
    #endif  // DEBUG
}

void    ScalarConverter::convert(char *p)
{
    int type = getInputType(p);
    switch (type)
    {
    case CHAR :
        // int i = static_cast<int>();
        // char c = static_cast<int>();
        // float f = static_cast<int>();
        // double d = static_cast<int>();
        std::cout << "char: " << std::endl;
        std::cout << "int: " << std::endl;
        std::cout << "float: " << std::endl;
        std::cout << "double: " << std::endl;
        break ;
    
    case INT :
        /* use atoi */

        // int i = static_cast<int>();
        // char c = static_cast<int>();
        // float f = static_cast<int>();
        // double d = static_cast<int>();
        std::cout << "char: " << std::endl;
        std::cout << "int: " << std::endl;
        std::cout << "float: " << std::endl;
        std::cout << "double: " << std::endl;
        break ;
    
    case FLOAT :
        /* use atof */

        // int i = static_cast<int>();
        // char c = static_cast<int>();
        // float f = static_cast<int>();
        // double d = static_cast<int>();
        std::cout << "char: " << std::endl;
        std::cout << "int: " << std::endl;
        std::cout << "float: " << std::endl;
        std::cout << "double: " << std::endl;
        break ;
    
    case DOUBLE :
        /* use atof */

        // int i = static_cast<int>();
        // char c = static_cast<int>();
        // float f = static_cast<int>();
        // double d = static_cast<int>();
        std::cout << "char: " << std::endl;
        std::cout << "int: " << std::endl;
        std::cout << "float: " << std::endl;
        std::cout << "double: " << std::endl;
        break ;

    default:
        std::cout << "Unknow type!" << std::endl;
        break;
    }
    return ;
}