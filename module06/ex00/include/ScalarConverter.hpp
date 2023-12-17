#if !defined(SCALARCONVERTER_HPP)
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>

class ScalarConverter {
private :
    ScalarConverter();
    ScalarConverter(ScalarConverter &rhs);
    ScalarConverter&    operator=(ScalarConverter &rhs);
    virtual ~ScalarConverter() = 0;

public:
    static void convert(std::string input);
};

#endif // SCALARCONVERTER_HPP