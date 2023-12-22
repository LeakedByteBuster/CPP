#if !defined(MUTANTSTACK_HPP)
#define MUTANTSTACK_HPP

#include <vector>
#include <deque>
#include <stack>

template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T, container > {

public:
    // MutantStack() : std::stack<T, container >() {
        
    // }

    // stack(MutantStack<T> &) {

    // }
    // MutantStack() : std::stack<T, std::vector<T> >() {}
    // MutantStack<T>&    operator=(MutantStack<T> &){}

    typedef typename container::iterator    iterator;
    iterator    begin() {
        return (this->c.begin());
    }
    iterator    end() {
        return (this->c.end());
    }
};


#endif // MUTANTSTACK_HPP