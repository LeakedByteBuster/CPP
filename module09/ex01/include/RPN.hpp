#if !defined(RPN_HPP)
#define RPN_HPP

#include <stack>
#include <string>

typedef enum {
    OP_UNKNOWN,
    OP_PLUS, // '+'
    OP_MINUS, // '-'
    OP_DIV, // '/'
    OP_MULTP // '*'
}   t_ops;

double    RPNcalculator(const char *p);

#endif // RPN_HPP