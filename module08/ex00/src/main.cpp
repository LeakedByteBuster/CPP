#include "easyfind.hpp"
#include <list>
#include <vector>

int main()
{
    std::list<int>    arr;
    unsigned long i = 0;
    for (i = 0; i < 10; i++){
        arr.push_front(i);
        std::cout << ' ' << arr.front();
    }
    std::cout << "\n ^ list<int> ^\n";
    easyfind(arr, 1);

    std::vector<int>    ar(10);
    for(int i = 0; static_cast<__SIZE_TYPE__>(i) < ar.size(); i++){
        ar[i] = i;
        std::cout << ' ' << ar[i];
    }
    std::cout << "\n ^ vector<int> ^\n";
    easyfind(arr, 1);
    
    std::string str("\n Hello\n");
    std::cout << str;
    std::cout << " ^ string ^\n";
    easyfind(arr, '1');
    return (0);
}
