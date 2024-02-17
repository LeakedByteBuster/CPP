#include "PmergeMe.hpp"

/* -------------------------------------------------------------------------- */
/*                              Utils Functions                               */
/* -------------------------------------------------------------------------- */

std::vector<size_t>    generateJacobsthalSeq(size_t n)
{
    std::vector<size_t>     s;
    size_t                  vecLen = n;
    size_t                  JacobNum = 0;
    
    if (n == 0)
        s.push_back(0);
    if (n == 1)
        s.push_back(1);
    if (n > 1) {
        s.push_back(0);
        s.push_back(1);
        n -= 2;
        for (size_t i = 1; n > 1; i++) {
            JacobNum = s[i] + (2 * s[i - 1]);
            if (JacobNum < vecLen) {
                s.push_back(JacobNum);
                n--;
                continue ;
            }
            break;
        }
        s.push_back(vecLen - 1); // size of input will be the last element in the sequence
    }

    return (s);
}
