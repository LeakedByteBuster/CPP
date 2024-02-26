#include <iostream>
#include <iomanip>
#include <cfloat>
#include <limits>
#include <climits>
#include <cmath>
#include <stdlib.h>

static bool    checkChar(double c)
{
    if (isascii(c)){
        if (!isprint(c)){
            std::cout << "char : Non Displayable\n";
            return (0);
        }
        return (1);
    }
    std::cout << "char : impossible\n";
    return (0);
}

static bool    checkInt(double i)
{
    if (i >= INT_MIN && i <= INT_MAX)
        return (1);
    std::cout << "int : impossible\n";
    return (0);
}

static bool checkFloat(double f)
{
    if ((f <= FLT_MAX && f >= FLT_MIN) || isinf(f) || isnan(f))
        return (1);
    std::cout << "float : impossible\n";
    return (0);
}

void    convertToChar(char c)
{
    std::cout << "char : " << c << "\n";
    std::cout << "int : " << static_cast<int>(c) << "\n";
    std::cout << std::fixed;
    std::cout << std::setprecision(1) << "float : " << static_cast<float>(c) 
        << "f\n";
    std::cout << std::setprecision(1) << "double : " << static_cast<double>(c) 
        << "\n";
}

void    convertToInt(std::string input)
{
    char    *endptr;
    double    res = strtod(input.data(), &endptr);

    if (res <= INT_MAX && res >= INT_MIN){
        int     i = atoi(input.data());
        if (checkChar(i))
            std::cout << "char : " << static_cast<char>(i) << "\n";
        std::cout << "int : " << i << "\n";
        std::cout << std::fixed;
        std::cout << std::setprecision(1) << "float : " << static_cast<float>(i) << "f\n";
        std::cout << std::setprecision(1) << "double : " << static_cast<double>(i) << "\n";
    }
    else {
        std::cout << "Warning : conversion from int makes no sense\n";
    }
}

void    convertToFloat(std::string input)
{
    char    *endptr;
    double    res = strtod(input.data(), &endptr);

    if ((res <= FLT_MAX && res >= FLT_MIN) || isinf(res) || isnan(res)){
            float   f = strtof(input.data(), &endptr);
            if (checkChar(f))
                std::cout << "char : " << static_cast<char>(f) << "\n";
            if (checkInt(f))
                std::cout << "int : " << static_cast<int>(f) << "\n";
            std::cout << std::fixed;
            std::cout << std::setprecision(1) <<"float : " << f << "f\n";
            std::cout << std::setprecision(1) << "double : " << 
                static_cast<double>(f) << "\n";
    }
    else {
        std::cout << "Warning : conversion from float makes no sense\n";
    }
}

void    convertToDouble(std::string input)
{
    char    *endptr;
    long double    d = strtold(input.data(), &endptr);

    if ((d >= std::numeric_limits<double>::min() 
        && d <= std::numeric_limits<double>::max()) || isinf(d) || isnan(d)){
            d = strtod(input.data(), &endptr);
            if (checkChar(d))
                std::cout << "char : " << static_cast<char>(d) << "\n";
            if (checkInt(d))
                std::cout << "int : " << static_cast<int>(d) << "\n";
            std::cout << std::fixed;
            if (checkFloat(d)){
                if (isnan(d) || isinf(d))
                    std::cout << std::setprecision(1) << "float : " << static_cast<float>(d) << "f\n";
                else
                    std::cout << std::setprecision(1) << "float : " << static_cast<float>(d) << "\n";
            }
            std::cout << std::setprecision(1) << "double : " << d << "\n";
    }
    else {
        std::cout << "Warning : conversion from double makes no sense\n";
    }
}
