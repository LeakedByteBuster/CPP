#include "PmergeMe.hpp"

int main(int ac, const char **av)
{
    try {
        if (ac < 2)
            throw std::invalid_argument("Error: not enough parameters");
//      check if there is an odd number of elements, duplicate, negative numbers
        PmergeMe    sorter(av);
        std::cout << sorter << std::endl;

//      pair the elements (n/2 element) and swap (B1, A1, ..., Bi, Ai)
//      split larger values from lower ones 
//      recursively sort the large elements in ascending order (A1, ..., An)
//      push elements of pending chain in main chain using jacobstahl sequence
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
