#include "BitcoinExchange.hpp"

enum    tokens {
    DAY,
    MONTH,
    YEAR,
    VALUE
};

static bool isStringDigit(std::string str, size_t size)
{
    size_t i = 0;
    for (; i < size; i++)
        if (!std::isdigit(str[i]))
            break;
    return (i == size ? 1 : 0);
}

static bool checkRange(std::string str, int type)
{
    double d = std::strtod(str.data(), NULL);
    int ret = 0;

    switch (type)
    {
    case YEAR:
        ret = (((d > 2008) && (d < 2023)) ? 1 : 0);
        break;

    case MONTH:
        ret = (((d > 0) && (d < 13)) ? 1 : 0);
        break;

    case DAY:
        ret = (((d > 0) && (d < 32)) ? 1 : 0);
        break;

    default:
        std::cout << "Warning: unknown type" << std::endl;
    }
    return (ret);
}

// The year must be evenly divisible by 4;
// If the year can also be evenly divided by 100, it is not a leap year;
// unless...
// The year is also evenly divisible by 400. Then it is a leap year.
bool    isLeapYear(int year)
{
    int ret = ((year % 4) == 0) ? 1 : 0;
    if (ret && (year % 100) == 0) {
        ret = ((year % 400) == 0) ? 1 : 0;
    }
    return (ret);
    
}

bool    checkDateExistence(const std::string &year, const std::string &month,
            const std::string &day)
{
    int y = std::atoi(year.data());
    int m = std::atoi(month.data());
    int d = std::atoi(day.data());

    if ((m == 2) && d > 28) {
        if (!isLeapYear(y) || d > 29) { return (0); }
    }
    if ((m % 2) == 0) {
        if (m != 8 && d > 30) { return (0); }
    }
    return (1);
}

bool    isDateCorrect(std::string &sub)
{
    /* parse year */
    size_t  pos = sub.find('-');
    std::string year = sub.substr(0, pos);
    if ((pos == std::string::npos) || !isStringDigit(year, 4) 
        || !checkRange(year, YEAR)) {
        return (0);
    }

    /* parse month */
    size_t  pos2 = sub.find('-', pos +1);
    // pos2 - 1 = removeSpaceAtEnd - pos = length of str between the two '-'
    std::string month = sub.substr(pos + 1, (pos2 - pos - 1));
    if (!isStringDigit(month, 2) || (pos == std::string::npos)
            || !checkRange(month, MONTH)) {
        return (0);
    }

    /* parse day */
    size_t  pos3 = sub.find(' ', pos2 + 1);
    std::string day = sub.substr(pos2 + 1, pos3 - pos2 - 1);
    if (!isStringDigit(day, 2) || (pos == std::string::npos)
            || !checkRange(day, DAY)) {
        return (0);
    }

    if (sub.compare("2009-01-02") < 0) {
        return(0);
    }
    return (checkDateExistence(year, month, day));
}

bool    isValueCorrect(std::string &sub)
{
    char    *endptr = NULL;

    double d = std::strtod(sub.data(), &endptr);
    if (*endptr != '\0') {
        std::cout << BitcoinExchange::getError("", BAD_INPUT) << std::endl;
        return (0);
    }
    if (d < 0) {
        std::cout << BitcoinExchange::getError("", NOT_A_POSITIVE) << std::endl;
        return (0);
    }
    if (d > 1000) {
        std::cout << BitcoinExchange::getError("", TOO_LARGE_NUMBER) << std::endl;
        return (0);
    }
    return (1);
}

