#if !defined(MUTANTSTACK_HPP)
#define MUTANTSTACK_HPP

#include <vector>
#include <deque>
#include <stack>

template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T, container > {

public:
    MutantStack() : std::stack<T, container>() { }
    
    MutantStack(MutantStack<T, container> &rhs) {
        *this = rhs;
    }

    MutantStack<T, container>&    operator=(MutantStack<T, container> &rhs) {
        if (this != &rhs)
            this->c = rhs.c;
        return (*this);
    }

    ~MutantStack() {}

    typedef typename container::iterator    iterator;
    iterator    begin() {
        return (this->c.begin());
    }

    iterator    end() {
        return (this->c.end());
    }
};

#endif // MUTANTSTACK_HPP