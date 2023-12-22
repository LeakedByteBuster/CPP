#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "MutantStack.hpp"

int main()
{


    MutantStack<int>    mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite)
    // {
    // std::cout << *it << std::endl;
    // ++it;
    // }
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }

    return 0;

    // int size = 10;
    // std::stack<int, std::vector<int> > s;
    // srand(time(NULL));
    // for (int i = 0; i < size; i++)
    //     s.push(rand() % 100);

    // while (!s.empty()){
    //     std::cout << s.top() << " ";
    //     s.pop();
    // }
    // std::cout << "\n";
}