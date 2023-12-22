#include <stdexcept>
#include <limits.h> // INT_MAX
#include <time.h> 
#include <stdlib.h>
#include "Span.hpp"


Span::Span()
{
    std::cerr << "Error : use parameterized constructor\n";
    exit(1);
}

Span::Span(unsigned int N) : toStore(N)
{
    toStore = N;
}

Span::Span(Span &rhs)
{
    *this = rhs;
}

Span&    Span::operator=(Span &rhs)
{
    if (this != &rhs){
        this->set = rhs.set;
        toStore = rhs.toStore;
    }
    return (*this);
}

Span::~Span()
{
    #if defined(PRINT)
        std::cout << "Destructor called\n";
    #endif // PRINT
}

void    Span::addNumber(unsigned int n)
{
    try {
        if (set.size() == toStore)
            throw std::range_error(" Maximum allowed storage is reached");
        set.insert(n);
    } catch (std::exception &e){
        std::cout << e.what() << "\n";
        return ;
    }
}

unsigned int    Span::shortestSpan()
{
    try {
        if (set.size() <= 1)
            throw std::invalid_argument("\nError : invalid arguments");
        
        int sp = INT_MAX;
        std::multiset<int>::iterator it = set.begin();
        for (int prev = *it;;){
            it++;
            if (it == set.end()) { break ; }
            if ((*it - prev) < sp) { sp = *it - prev; }
            prev = *it;
        }
        return (sp);
    
    } catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
    return (0);
}

unsigned int    Span::longestSpan()
{
    try {
        if (set.empty() || (set.size() == 1))
            throw std::invalid_argument("\nError : invalid arguments");
        return ((*(set.rbegin())) - (*(set.begin())));
        } catch (std::exception &e) {
            std::cout << e.what() << "\n";
        }
    return (0);
}

void  Span::printSet() const
{
    std::cout << " list : ";
    std::multiset<int>::iterator    it;
    for (it = set.begin(); it != set.end(); it++){
        std::cout << " " << *it;
    }
    std::cout << "\n";
}


void    Span::fillSet(const unsigned long n)
{
    try {
        if (n <= (toStore - set.size())) {
            srand(time(NULL));
            std::multiset<int>::iterator    it;
            for (unsigned long i = 0; i < n; i++){
                set.insert(rand() % INT_MAX);
            }
            return ;
        }
        throw std::invalid_argument("Error : not enough space");
    } catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
}
