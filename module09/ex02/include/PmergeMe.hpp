#if !defined(PMERGEME_HPP)
#define PMERGEME_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>
#include <string>


class PmergeMe {
public:
    std::vector<std::pair<int, int> >   seq; // number sequence
    std::vector<int>                    mainChain;
    std::vector<int>                    pendChain;
    bool                                isOdd;
    int                                 oddNum;

    PmergeMe(const char **av);
    ~PmergeMe();

    int     strToInt(const char *av); // throws except
    void    swapElementInSeq();
    void    fillMainAndPendChain();
    void    insertPendIntoMain();

};

std::ostream&       operator<<(std::ostream &os, const PmergeMe &s);
std::vector<size_t> generateJacobsthalSeq(size_t n);

template<typename T>
std::ostream&       operator<<(std::ostream &os, const std::vector<T> &s)
{
    for (size_t i = 0; i < s.size(); i++) {
        os << " " << s[i];
    }
    return (os);
}

template<typename T>
inline void    printLog(T a, const std::string s) {
    std::cout << s << " " << a << std::endl;
}

#endif // PMERGEME_HPP