#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point   s(66.5, 662.4);
    Point   k(6.5, 6.4);
    Point   a(s);


    std::cout << a.getX() << " | " << a.getY() << std::endl;
    std::cout << s.getX() << " | " << s.getY() << std::endl;

    a = k;

    std::cout << a.getX() << " | " << a.getY() << std::endl;

    return 0;
}
