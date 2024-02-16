#include "PmergeMe.hpp"

static void    fillNumbersInSeq(std::vector<std::pair<int, int> > &dst, const std::vector<int> &src);
static void    checkDuplicate(const std::vector<int> &lst, const int &odd, const bool &isOdd);

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
PmergeMe::PmergeMe(const char **av) : isOdd(0), oddNum(0)
{

    // convert to int and check if num of args is odd
    std::vector<int>    lst;
    for (size_t i = 1; av[i] != NULL; i++) {
        lst.push_back(strToInt(av[i]));
    }
    if ((lst.size() % 2) != 0) {
        isOdd = 1;
        oddNum = lst.back();
        lst.erase(lst.end() - 1);
    }
    checkDuplicate(lst, oddNum, isOdd);
    // fill the std::vector<pair...> Seq in the class using lst vector
    fillNumbersInSeq(this->seq, lst);
}

PmergeMe::~PmergeMe() { }

/* -------------------------------------------------------------------------- */
/*                              Member Functions                              */
/* -------------------------------------------------------------------------- */

int     PmergeMe::strToInt(const char *av)
{
    char    *endptr = NULL;

    errno = 0;
    int res = std::strtol(av, &endptr, 10);
    if ((*endptr != '\0') || (res < 0) || (errno == ERANGE) || res > INT_MAX)
        throw std::invalid_argument("Error: invalid input: " + static_cast<std::string>(av));

    return (res);
}

void    PmergeMe::fillMainAndPendChain()
{
    for (size_t i = 0; i < seq.size(); i++) {
        mainChain.push_back(seq[i].first);
        pendChain.push_back(seq[i].second);
    }
    if (isOdd) {
        pendChain.push_back(oddNum);
    }
}

void    PmergeMe::insertPendIntoMain()
{
    
}

void    PmergeMe::swapElementInSeq()
{
    int tmp  = 0;
    for (size_t i = 0; i < seq.size(); i++) {
        if (seq[i].first < seq[i].second) {
            tmp  = seq[i].first;
            seq[i].first = seq[i].second;
            seq[i].second = tmp;
        }
    }
    generateJacobsthalSeq(2);
    
}

/* -------------------------------------------------------------------------- */
/*                              Utils Functions                               */
/* -------------------------------------------------------------------------- */


std::vector<size_t>    generateJacobsthalSeq(size_t n)
{
    std::vector<size_t>     s;
    size_t                  len = n;
    
    if (n == 0)
        s.push_back(0);
    if (n == 1)
        s.push_back(1);
    if (n > 1) {
        s.push_back(0);
        s.push_back(1);
        n -= 2;
        for (size_t i = 1; n > 1; i++) {
            if (i < len) {
                s.push_back(s[i] + (2 * s[i - 1]));
            }
            n--;
        }
        s.push_back(len); // size of input will be the last element in the sequence
    }
    printLog(s, "jacob:");

    return (s);
}

static void    fillNumbersInSeq(std::vector<std::pair<int, int> > &dst, const std::vector<int> &src)
{
    for (size_t i = 1; i < src.size(); i++) {
        if ((i > 0) && ((i % 2) != 0)) {
                dst.push_back(
                std::make_pair(src[i - 1], src[i])
            );
        }
    }
}

static void    checkDuplicate(const std::vector<int> &lst, const int &odd, const bool &isOdd)
{
    int check = 0;
    for (size_t i = 0; i < lst.size(); i++) {
        check = lst[i];
        for (size_t j = 0; j < lst.size(); j++) {
            if (i != j) {
                if (check == lst[j]) {
                    throw std::invalid_argument("Error: duplicate number");
                }
            }
        }
    }
    if (isOdd) {
        for (size_t j = 0; j < lst.size(); j++) {
                if (odd == lst[j]) {
                    throw std::invalid_argument("Error: duplicate number");
                }
            }
    }
}

/* -------------------------------------------------------------------------- */
/*                                 Overloads                                  */
/* -------------------------------------------------------------------------- */

std::ostream&   operator<<(std::ostream &os, const PmergeMe &s)
{
    for (size_t i = 0; i < s.seq.size(); i++) {
        os << " " << s.seq[i].first << " " << s.seq[i].second;
    }
    if (s.isOdd)
        os << " | odd = " << s.oddNum;
    return (os);
}
