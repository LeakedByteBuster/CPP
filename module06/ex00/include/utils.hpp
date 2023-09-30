#if !defined(UTILS_HPP)
#define UTILS_HPP


enum INPUT_TYPES{
    UNKNOWN,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NOTAN
};

bool    isInputZero(char *p);
int     inputType(char *p);
#endif // UTILS_HPP
