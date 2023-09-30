#if !defined(UTILS_HPP)
#define UTILS_HPP

#include <string>

enum INPUT_TYPES{
    UNKNOWN,
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

int getInputType(std::string p);
#endif // UTILS_HPP
