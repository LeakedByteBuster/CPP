#include "PmergeMe.hpp"

static void    fillNumbersInSeq(std::vector<std::pair<int, int> > &dst, const std::vector<int> &src);
static void    checkDuplicate(const std::vector<int> &lst, const int &odd, const bool &isOdd);

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

std::ostream&   operator<<(std::ostream &os, const PmergeMe &s)
{
    os << "Initial List:";
    for (size_t i = 0; i < s.seq.size(); i++) {
        os << " " << s.seq[i].first << " " << s.seq[i].second;
    }
    if (s.isOdd)
        os << " | odd = " << s.oddNum;
    return (os);
}

int     PmergeMe::strToInt(const char *av)
{
    char    *endptr = NULL;

    errno = 0;
    int res = std::strtol(av, &endptr, 10);
    if ((*endptr != '\0') || (res < 0) || (errno == ERANGE) || res > INT_MAX)
        throw std::invalid_argument("Error: invalid input: " + static_cast<std::string>(av));

    return (res);
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