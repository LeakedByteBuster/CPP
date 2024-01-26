#include <sstream>
#include <cstdlib>
#include "RPN.hpp"

inline short   whichOp(const std::string &s)
{
    int res =     (s.compare("+") == 0) * OP_PLUS
                + (s.compare("-") == 0) * OP_MINUS
                + (s.compare("*") == 0) * OP_MULTP
                + (s.compare("/") == 0) * OP_DIV;

    return (res);
}

static void calculateElements(std::stack<double> &rpn, const std::string &token)
{
    double  top = rpn.top();
    rpn.pop();
    double  prev = rpn.top();
    rpn.pop();

    switch (whichOp(token))
    {
    case OP_PLUS:
        rpn.push(prev + top);
        break;

    case OP_MINUS:
        rpn.push(prev - top);        
        break;

    case OP_MULTP:
        rpn.push(prev * top);
        break;

    case OP_DIV:
        rpn.push(prev / top);
        break;

    default:
        throw std::runtime_error("Error: invalid argument");
        break;
    }
    return ;
} 

double    RPNcalculator(const char *p)
{
    std::stack<double> rpn;
    std::stringstream   ss(p);
    std::string         token;
    char                *endptr = NULL;
    double              num = 0;

    while (ss >> token) {
        // if it's a number push it and continue
        num = std::strtod(token.data(), &endptr);
        if (*endptr == '\0') {
            rpn.push(num);
            continue ;
        }
        // it's a operator, does calculation
        if (rpn.size() >= 2) {
            calculateElements(rpn, token);
            continue ;
        }
        throw std::runtime_error("Error: in token : " + token);
    }

    double res = rpn.top();
    rpn.pop();
    if (rpn.size() != 0)
        throw std::runtime_error("Error: invalid argument");
    return (res);
}