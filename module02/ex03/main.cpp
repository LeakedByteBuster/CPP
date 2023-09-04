#include "Point.hpp"

// Compilation:
// make CXXFLAGS+="-DNDEBUG -DNDEBUG_BSP"
int main(void)
{
    Point   a(0.0, 1.0);
    Point   b(2.0, 2.0);
    Point   c(2.0, 0.0);
    Point   point(1.90, 0.5);

    #ifndef NDEBUG
        std::cout << a.getX() << " | " << a.getY() << std::endl;
        std::cout << b.getX() << " | " << b.getY() << std::endl;
        a = c;
        std::cout << a.getX() << " | " << a.getY() << std::endl;
    #endif // NDEBUG
    if (bsp(a, b, c, point) == 1)
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;

    return 0;
}
