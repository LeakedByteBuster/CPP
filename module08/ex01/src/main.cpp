#include "Span.hpp"
#include <time.h> 
#include <limits.h> // INT_MAX
#include <stdlib.h>

int main()
{
    int size = 5;
    Span    sp(size);

    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    // sp.addNumber(9);

    srand(time(NULL));
    std::multiset<int>  tmp;
    for (int i = 0; i < size; i++){
        tmp.insert(rand() % INT_MAX);
    }
    sp.fillSet(tmp.begin(), tmp.end(), tmp.size());
    sp.printSet();
    std::cout << " longest sp : " <<  sp.longestSpan() << "\n";
    std::cout << " shortest sp : " <<  sp.shortestSpan() << "\n";
    return (0);
}
