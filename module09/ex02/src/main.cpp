#include <sys/time.h>
#include <ctime>
#include <iomanip>
#include "PmergeMe.hpp"

static inline void  printTime(size_t size, double time, std::string cont)
{
    std::cout << std::fixed << "Time to process a range of " << size << " elements with "
        << cont << " : " << time << " s" << std::endl;
}
/*
> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[.0.] : 69.27212 us

*/
int main(int ac, const char **av)
{
    try {
        if (ac < 2)
            throw std::invalid_argument("Error: not enough parameters");
//      check if there is an odd number of elements, duplicate, negative numbers, and pair elements
        clock_t start = clock();
        
        PmergeMe    sorter(av);
        printLog(sorter, "[ Before ]");

        sorter.swapElementInSeq();
        std::sort(sorter.seq.begin(), sorter.seq.end());
        sorter.fillMainAndPendChain();
        sorter.insertPendIntoMain();        
        double execTime = (double)(clock() - start) / CLOCKS_PER_SEC;
        printLog(sorter.mainChain, "[ After ]");

        printTime(sorter.mainChain.size(), execTime, "std::vector<int>");

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}

