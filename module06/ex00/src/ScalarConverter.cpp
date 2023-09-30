#include <iostream>
#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <stdlib.h>


#define PRINT_ALL   std::cout << "char: " << c << std::endl; \
                    std::cout << "int: " << i << std::endl; \
                    std::cout << "float: " << f << "f" << std::endl; \
                    std::cout << "double: " << d << std::endl;


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
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    bool    errorOccured = 0;
    long long   check = 0;
    // bool    isZero = isInputZero(p);
    int     type = inputType(p);

    std::cout << std::fixed;
    std::cout.precision(1);
    switch (type)
    {
    case CHAR :
        c = *p;
        i = static_cast<int>(*p);
        f = static_cast<float>(*p);
        d = static_cast<double>(*p);
        PRINT_ALL;
        break ;

    case INT :
        check = strtoll(p, NULL, 10);
        // std::cout << check << " " << isInputZero(p) << std::endl;

        if ((check > INT_MAX || check < INT_MIN) || (check == 0 && !isInputZero(p)))
            errorOccured = 1;
        i = check;
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);

        if (!errorOccured) {
            if (isprint(i))
                std::cout << "char: " << c << std::endl;
            else if (isascii(i) && !isprint(i))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: Impossible" << std::endl;
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        }
        else {
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: Impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        break ;

    case FLOAT:
    check = strtof(p, NULL);
    if (errno == ERANGE){
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: Impossible" << std::endl;
        std::cout << "double: Impossible" << std::endl;
    }
    else
    {
        d = atof(p);
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    }

    break ;

    case DOUBLE :
        check = strtod(p, NULL);
        if ((errno != ERANGE) && ((check != HUGE_VALL) || (check != -HUGE_VALL))) {
            d = check;
            c = static_cast<char>(d);
            i = static_cast<int>(d);
            f = static_cast<float>(d);

            if ((check <= INT_MAX && check >= INT_MIN)) {
                if (isprint(i))
                    std::cout << "char: " << c << std::endl;
                else if (isascii(i) && !isprint(i))
                    std::cout << "char: Non displayable" << std::endl;
                std::cout << "int: " << i << std::endl;
            }
            else {
                std::cout << "char: Impossible" << std::endl;
                std::cout << "int: Impossible" << std::endl;
            }
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        } else {
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: Impossible" << std::endl;
            std::cout << "float: Impossible" << std::endl;
            std::cout << "double: Impossible" << std::endl;
        }

        break ;

    case NOTAN :

        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: " << atof(p) << "f" << std::endl;
        std::cout << "double: " << atof(p) << std::endl;
        break ;

    default :
        std::cout << "Unknown type" << std::endl;
        break; 
    }
    
    return ;
}
