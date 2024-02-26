#if !defined(EASYFIND_HPP)
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>


template <typename T>
typename T::iterator    easyfind(T &ctr, int i)
{
    typename T::iterator    it;

    try {
        it = std::find(ctr.begin(), ctr.end(), i);
        if (it == ctr.end())
            throw std::out_of_range(" Not Found\n");
        std::cout << " Found\n";
    } catch (std::exception &e){
        std::cout << e.what();
        return (ctr.end());
    }
    return (it);
}


#endif // EASYFIND_HPP