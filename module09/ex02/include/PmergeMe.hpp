#if !defined(PMERGEME_HPP)
#define PMERGEME_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <string>


class PmergeMe {
public:
    std::vector<std::pair<int, int> >   seq; // number sequence
    bool    isOdd;
    int     oddNum;

    PmergeMe(const char **av);
    ~PmergeMe();

    int strToInt(const char *av); // throws except


};

std::ostream    &operator<<(std::ostream &os, const PmergeMe &s);

#endif // PMERGEME_HPP