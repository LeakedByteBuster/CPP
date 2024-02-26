#include <iostream>
#include <iter.hpp>

template <typename T>
void   squareNumber(T x) {
    std::cout << x << " * " << x << " = " << x * x << "\n";
}

void    printInt(int p) {
    std::cout << p << "\n";
}

void    printChar(const char p) {
    std::cout << p << "\n";
}

int main(void) {

    int x[5] = {1, 2, 3, 4, 5};
    iter(x, 5, printInt);

    iter(x, 5, squareNumber<int>);

    const char *p = "hello\n";
    iter(p, 5, printChar);

    return (0);
}