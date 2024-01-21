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
        ret = (((d > 2009) && (d < 2022)) ? 1 : 0);
        break;

    case MONTH:
        ret = (((d > 0) && (d < 13)) ? 1 : 0);
        break;

    case DAY:
        ret = (((d > 0) && (d < 31)) ? 1 : 0);
        break;

    default:
        std::cout << "Warning: unknown type" << std::endl;
    }
    return (ret);
}

bool    isDateCorrect(std::string &sub)
{
    /* parse year */
    size_t  pos = sub.find('-');
    std::string year = sub.substr(0, pos);
    if (!isStringDigit(year, 4) || (pos == std::string::npos)
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
    std::string date = sub.substr(pos2 + 1, pos3 - pos2 - 1);
    if (!isStringDigit(date, 2) || (pos == std::string::npos)
            || !checkRange(date, DAY)) {
        return (0);
    }

    return (1);
}

bool    isValueCorrect(std::string &sub)
{
    char    *endptr = NULL;

    double d = std::strtod(sub.data(), &endptr);
    (void)d;
    if (*endptr != '\0') {
        return (0);
    }
    
    return (1);
}