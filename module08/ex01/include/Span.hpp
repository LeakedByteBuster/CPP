#if !defined(SPAN_HPP)
#define SPAN_HPP

#include <iostream>
#include <set>

class Span
{
private:
    std::multiset<int>  set;
    unsigned int        toStore;

public:
    Span();
    Span(unsigned int N);
    Span(Span &rhs);
    Span&    operator=(Span &rhs);
    ~Span();

    void            addNumber(unsigned int n);
    unsigned int    shortestSpan();
    unsigned int    longestSpan();
    void            printSet() const;
    void            fillSet(const unsigned long n);
};



#endif // SPAN_HPP