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
        std::sort(sorter.seq.begin(), sorter.seq.end());
        sorter.fillMainAndPendChain();
        sorter.insertPendIntoMain();

        printLog(sorter.mainChain, "--> ");
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}

