#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <list>
#include "MutantStack.hpp"

int main()
{
    /******************** MutantStack ********************/

    MutantStack<int>    tack;
    tack.push(999);
    tack.push(998);
    
    MutantStack<int>    mstack(tack);
    std::cout << "top = " <<  mstack.top() << std::endl;
    std::cout << "size = " << mstack.size() << std::endl;
    mstack.pop();
    mstack.pop();

    mstack.push(5);
    mstack.push(17);
    mstack.pop();
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "mstack {\n";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++){
        std::cout << *it << "\n";
    }
    std::cout << "}\ntack {\n";
    MutantStack<int>::iterator it = tack.begin();
    MutantStack<int>::iterator ite = tack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << "\n";
        ++it;
    }
    std::cout << "}\n";
    std::stack<int> s(mstack);

    /******************** List ********************/
    // std::list<int>    tack;
    // tack.push_back(999);
    // tack.push_back(998);
    
    // std::list<int>    mstack(tack);
    // std::cout << "top = " <<  mstack.front() << std::endl;
    // std::cout << "size = " << mstack.size() << std::endl;
    // mstack.remove(999);
    // mstack.remove(998);

    // mstack.push_back(5);
    // mstack.push_back(17);
    // mstack.remove(17);
    // mstack.push_back(3);
    // mstack.push_back(5);
    // mstack.push_back(737);
    // mstack.push_back(0);

    // std::cout << "mstack {\n";
    // for (std::list<int>::iterator it = mstack.begin(); it != mstack.end(); it++){
    //     std::cout << *it << "\n";
    // }
    // std::cout << "}\ntack {\n";
    // std::list<int>::iterator it = tack.begin();
    // std::list<int>::iterator ite = tack.end();
    // ++it;
    // --it;
    // while (it != ite)
    // {
    //     std::cout << *it << "\n";
    //     ++it;
    // }
    // std::cout << "}\n";
    // std::list<int> s(mstack);
    return 0;
}