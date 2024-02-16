#include "PmergeMe.hpp"

static void    fillNumbersInSeq(std::vector<std::pair<int, int> > &dst, const std::vector<int> &src);
static void    checkDuplicate(const std::vector<int> &lst, const int &odd, const bool &isOdd);


// 61 49 79 73 41 26 6 82 17 64 95 29 54 21 78 40 96 44 87 93 81 16 90 37 3 34 47 97 67 59 48 98 88 33 31 42 58 10 23 86 11 74 24 75 66 14 83 46 100 71 53 13 4 55 18 92 80 28 43 76 45 94 7 60 9 91 77 2 38 99 25 12 70 39 89 57 20 1 8 52 35 51 72 56 84 68 32 62 65 27 30 15 36 
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
    if (pendChain.empty())
        return ;
    std::vector<size_t> jacobSeq = generateJacobsthalSeq(pendChain.size());
    mainChain.insert(mainChain.begin(), pendChain[0]);

    std::vector<int>::iterator  it;
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
}

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
        os << " " << s.oddNum;
    return (os);
}
