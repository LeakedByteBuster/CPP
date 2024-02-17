#include <ctime>
#include <iomanip>
#include "PmergeMe.hpp"

static inline void  printTime(size_t size, double time, std::string cont)
{
    std::cout << std::fixed << "Time to process a range of " << size << " elements with "
        << cont << " : " << time << " s" << std::endl;
}

int main(int ac, const char **av)
{
    try {
        if (ac < 2)
            throw std::invalid_argument("Error: not enough parameters");
//      check if there is an odd number of elements, duplicate, negative numbers, and pair elements
        clock_t start = clock();
        PmergeMe< std::vector< std::pair< int, int > >, std::vector< int >, std::vector< int > >    sorter(av);
        printLog(sorter, "[ Before ]");

        sorter.swapElementInSeq();
        std::sort(sorter.seq.begin(), sorter.seq.end());
        sorter.fillMainAndPendChain();
        sorter.insertPendIntoMain();        
        double execTime = (double)(clock() - start) / CLOCKS_PER_SEC;
        printLog(sorter.mainChain, "[ After ]");

        printTime(sorter.mainChain.size(), execTime, "std::vector<int>");


        clock_t startDeque = clock();
        
        PmergeMe< std::deque< std::pair< int, int > >, std::deque< int >, std::deque< int > >    sortDeque(av);
        sortDeque.swapElementInSeq();
        std::sort(sortDeque.seq.begin(), sortDeque.seq.end());
        sortDeque.fillMainAndPendChain();
        sortDeque.insertPendIntoMain();        
        double execTimeDeque = (double)(clock() - startDeque) / CLOCKS_PER_SEC;

        printTime(sortDeque.mainChain.size(), execTimeDeque, "std::deque<int>");

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}

