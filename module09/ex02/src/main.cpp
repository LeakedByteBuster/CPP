#include "PmergeMe.hpp"

int main(int ac, const char **av)
{
    try {
        if (ac < 2)
            throw std::invalid_argument("Error: not enough parameters");
//      check if there is an odd number of elements, duplicate, negative numbers, and pair elements
        PmergeMe    sorter(av);
        printLog(sorter, "Input:");
        
        sorter.swapElementInSeq();
        printLog(sorter, "swap:");
        std::sort(sorter.seq.begin(), sorter.seq.end());
        printLog(sorter, "sort:");
        sorter.fillMainAndPendChain();
        printLog(sorter.mainChain, "main:");
        printLog(sorter.pendChain, "pend:");
        

//      push elements of pending chain in main chain using jacobstahl sequence
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
