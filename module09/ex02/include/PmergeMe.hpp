#if !defined(PMERGEME_HPP)
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <list>

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>

/* -------------------------------------------------------------------------- */
/*                                Pmerge Class                                */
/* -------------------------------------------------------------------------- */

std::vector<size_t> generateJacobsthalSeq(size_t n);

template<typename seqType, typename mainChainType, typename pendChainType>
class PmergeMe {
public:
    seqType   seq; // number sequence
    mainChainType                    mainChain;
    pendChainType                    pendChain;
    bool                                isOdd;
    int                                 oddNum;

    PmergeMe();
    PmergeMe(const char **av);
    PmergeMe(const PmergeMe &rhs);
    PmergeMe    &operator=(const PmergeMe &rhs);
    ~PmergeMe();

    int     strToInt(const char *av); // throws except
    void    swapElementInSeq();
    void    fillMainAndPendChain();
    void    insertPendIntoMain();

    typedef typename mainChainType::iterator    iterator;
};

/* -------------------------------------------------------------------------- */
/*                                   Utils                                    */
/* -------------------------------------------------------------------------- */

template<typename srcType, typename dstType>
void    fillNumbersInSeq(srcType &dst, const dstType &src)
{
    for (size_t i = 1; i < src.size(); i++) {
        if ((i > 0) && ((i % 2) != 0)) {
                dst.push_back(
                std::make_pair(src[i - 1], src[i])
            );
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

template<typename seqType, typename mainChainType, typename pendChainType>
PmergeMe<seqType, mainChainType, pendChainType>::PmergeMe(const char **av) : isOdd(0), oddNum(0)
{

    // convert to int and check if num of args is odd
    mainChainType    lst;
    for (size_t i = 1; av[i] != NULL; i++) {
        lst.push_back(strToInt(av[i]));
    }
    if ((lst.size() % 2) != 0) {
        isOdd = 1;
        oddNum = lst.back();
        lst.erase(--(lst.end()));
    }
    // fill the std::vector<pair...> Seq in the class using lst vector
    fillNumbersInSeq(this->seq, lst);
}

template<typename seqType, typename mainChainType, typename pendChainType>
PmergeMe<seqType, mainChainType, pendChainType>::PmergeMe() : isOdd(0), oddNum(0)
{
}

template<typename seqType, typename mainChainType, typename pendChainType>
PmergeMe<seqType, mainChainType, pendChainType>::PmergeMe(const PmergeMe &rhs)
{
    *this = rhs;
}

template<typename seqType, typename mainChainType, typename pendChainType>
PmergeMe<seqType, mainChainType, pendChainType>    &PmergeMe<seqType, mainChainType, pendChainType>::operator=(const PmergeMe &rhs)
{
    if (this != &rhs) {
        isOdd = rhs.isOdd;
        oddNum = rhs.oddNum;
        seq = rhs.seq;
        mainChain = rhs.mainChain;
        pendChain = rhs.pendChain;
    }
    return (*this);
}

template<typename seqType, typename mainChainType, typename pendChainType>
PmergeMe<seqType, mainChainType, pendChainType>::~PmergeMe() { }

/* -------------------------------------------------------------------------- */
/*                              Member Functions                              */
/* -------------------------------------------------------------------------- */

template<typename seqType, typename mainChainType, typename pendChainType>
int PmergeMe<seqType, mainChainType, pendChainType>::strToInt(const char *av)
{
    char    *endptr = NULL;

    errno = 0;
    int res = std::strtol(av, &endptr, 10);
    if ((*endptr != '\0') || (res < 0) || (errno == ERANGE) || res > INT_MAX)
        throw std::invalid_argument("Error: invalid input: " + static_cast<std::string>(av));

    return (res);
}

template<typename seqType, typename mainChainType, typename pendChainType>
void    PmergeMe<seqType, mainChainType, pendChainType>::fillMainAndPendChain()
{
    for (size_t i = 0; i < seq.size(); i++) {
        mainChain.push_back(seq[i].first);
        pendChain.push_back(seq[i].second);
    }
    if (isOdd) {
        pendChain.push_back(oddNum);
    }
}

template<typename seqType, typename mainChainType, typename pendChainType>
void    PmergeMe<seqType, mainChainType, pendChainType>::insertPendIntoMain()
{
    if (pendChain.empty())
        return ;
    std::vector<size_t> jacobSeq = generateJacobsthalSeq(pendChain.size());
    mainChain.insert(mainChain.begin(), pendChain[0]);

    PmergeMe::iterator          it;
    size_t                      prevJacob = 0;
    size_t                      toInsert = 0;

    for (size_t i = 0; ; i++) {
        prevJacob = jacobSeq[i];
        size_t nextJacob = ((i + 1) < jacobSeq.size()) ? jacobSeq[i + 1] : pendChain.size() - 1;
        for (; nextJacob > prevJacob; nextJacob--) {
            toInsert = pendChain[nextJacob];
            it = std::upper_bound(mainChain.begin(), mainChain.end(), toInsert);
            mainChain.insert(it, toInsert);
        }
        if ((i + 1) >= jacobSeq.size())
            break;
    }
}
template<typename seqType, typename mainChainType, typename pendChainType>
void    PmergeMe<seqType, mainChainType, pendChainType>::swapElementInSeq()
{
    int tmp  = 0;
    for (size_t i = 0; i < seq.size(); i++) {
        if (seq[i].first < seq[i].second) {
            tmp  = seq[i].first;
            seq[i].first = seq[i].second;
            seq[i].second = tmp;
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                                 Overloads                                  */
/* -------------------------------------------------------------------------- */

template<typename seqType, typename mainChainType, typename pendChainType>
std::ostream&   operator<<(std::ostream &os, const PmergeMe<seqType, mainChainType, pendChainType> &s)
{
    for (size_t i = 0; i < s.seq.size(); i++) {
        os << " " << s.seq[i].first << " " << s.seq[i].second;
    }
    if (s.isOdd)
        os << " " << s.oddNum;
    return (os);
}

template<typename T>
std::ostream&       operator<<(std::ostream &os, const std::vector<T> &s)
{
    for (size_t i = 0; i < s.size(); i++) {
        os << " " << s[i];
    }
    return (os);
}

template<typename T>
std::ostream&       operator<<(std::ostream &os, const std::deque<T> &s)
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