#include <iostream>
#include <iomanip>
#include <cfloat>

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

// static bool checkFloat(double f)
// {
//     if (f <= FLT_MAX && f >= FLT_MIN)
//         return (1);
//     return (0);
// }

// static bool checkDouble(double f)
// {
//     if (f <= DBL_MAX && f >= DBL_MIN )
//         return (1);
//     return (0);
// }

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
    #if defined(CHECK)
        std::cout << "convertToInt called\n"
    #endif // CHECK

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
    #if defined(CHECK)
        std::cout << "convertToFloat called\n"
    #endif // CHECK
    char    *endptr;
    double    res = strtod(input.data(), &endptr);

    if ((res <= FLT_MAX && res >= FLT_MIN) || res == INFINITY || res != res ||
        res == -INFINITY){
            endptr = NULL;
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

void    convertToDouble(double d)
{
    // checkFloat(d);
    std::cout << "double : " << d << "\n";
}
