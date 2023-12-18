#if !defined(SCALARCONVERTER_HPP)
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>

class ScalarConverter {
private :
    ScalarConverter();

public:
    ScalarConverter(ScalarConverter &rhs);
    ScalarConverter&    operator=(ScalarConverter &rhs);
    ~ScalarConverter();

    static void convert(std::string input);
};

#endif // SCALARCONVERTER_HPP