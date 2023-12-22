#include "Span.hpp"

int main()
{
    int size = 10000;
    Span    sp(size);

    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    // sp.addNumber(9);

    sp.fillSet(size);
    // sp.addNumber(9);
    sp.printSet();
    std::cout << " longest sp : " <<  sp.longestSpan() << "\n";
    std::cout << " shortest sp : " <<  sp.shortestSpan() << "\n";
    return (0);
}