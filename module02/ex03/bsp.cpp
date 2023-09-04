#include "Point.hpp"
#include <cmath>

/*
*   To find area of the following triangle:
*       A(x1​,y1​)B(x2​,y2​)C(x3​,y3​)
*
*       Shoelace Formula;
*       ----------------
* -------------------------------------------------------------------------- *
*       Area of Δ = 1/2 * | x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2) |        *
* -------------------------------------------------------------------------- *
*   source: https://artofproblemsolving.com/wiki/index.php/Shoelace_Theorem
*/

static Fixed shoeLace(Point const a, Point const b, Point const c)
{
    Fixed div(0.5f);

    Fixed res = div * \
                ((a.getX() * (b.getY() - c.getY())) + \
                (b.getX() * (c.getY() - a.getY())) + \
                (c.getX() * (a.getY() - b.getY())));
    if (res < 0)
        res = res * -1;
    return (res);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed div(0.5f);

    Fixed   totalArea = shoeLace(a, b, c);
    #ifndef NDEBUG
        std::cout << "Total Area = " << totalArea << std::endl;
    #endif // NDEBUG
    
    Fixed   subArea1 = shoeLace(point, b, c);
    #ifndef NDEBUG
        std::cout << "subArea1 = " << subArea1 << std::endl;
    #endif // NDEBUG

    Fixed   subArea2 =  shoeLace(a, point, c);
    #ifndef NDEBUG
        std::cout << "subArea2 = " << subArea2 << std::endl;
    #endif // NDEBUG

    Fixed   subArea3 = shoeLace(a, b, point);
    #ifndef NDEBUG
        std::cout << "subArea3 = " << subArea3 << std::endl;
    #endif // NDEBUG

    Fixed sum = subArea1 + subArea2 + subArea3;
    #ifndef NDEBUG
        std::cout << "Sum = " << sum << std::endl;
    #endif // NDEBUG

    if (subArea1 == 0 || subArea2 == 0 || subArea3 == 0 || sum != totalArea)
        return (false);
    return (true);
}
