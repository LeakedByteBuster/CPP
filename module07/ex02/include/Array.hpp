#if !defined(ARRAY_HPP)
#define ARRAY_HPP

#include <stddef.h>
#include <stdexcept>
#include <iostream>

template <class T>
class Array{
private :
    unsigned int    len;
    T               *tab;

public :
    Array() : len(1), tab(NULL) {
        tab = new T();
    }

    Array(unsigned int n) : len(n), tab(NULL) {
        tab = new T[n];
    }

    Array(Array &rhs) : len(0), tab(NULL) {
        if (this == &rhs)
            return ;
        *this = rhs;
    }

    Array&  operator=(Array &rhs) {
        if (this->tab)
            delete[] tab;

        len = rhs.size();
        tab = new T[len];
        for (unsigned int i = 0; i < len; i++)
            tab[i] = rhs[i];
        return (*this);
    }

    virtual ~Array() {
        delete[] tab;
    }

    unsigned int   size() const {
        return (len);
    }

    template <typename U>
    T&   operator[](U i) const {
        try {
            if (static_cast<unsigned int>(i) <= len){
                return (this->tab[i]);
            }
            throw std::out_of_range("Error : out of range");
        } catch (std::exception &e) {
            std::cout << e.what() << "\n";
            exit(0);
        }
    }

};

#endif // ARRAY_HPP
