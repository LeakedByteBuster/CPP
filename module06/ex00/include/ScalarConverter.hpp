#if !defined(SCALARCONVERTER_HPP)
#define SCALARCONVERTER_HPP

class ScalarConverter
{
private:
    /* data */
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &rhs);
    ScalarConverter& operator=(const ScalarConverter &rhs);
    ~ScalarConverter();

    static void convert(char *input);
};

#endif // SCALARCONVERTER_HPP