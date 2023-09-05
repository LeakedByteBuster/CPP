/*
*   Triangle Used For TEST_CASES:
*   -----------------------------
*
*    yAxis
*    ^
*    |         
*    |
*   1|       /\ b (1.0, 1.0)
*    |      /  \
*    |     /    \
*    |    /      \
*    |   /        \
*    |  /          \
*    | /a (0.0, 0.0)\ 
*    |/______________\ c (2.0, 0.0)
*    +----------------------------------> xAxis
*   0        1        2
*
*/

#include <stdlib.h>
#include <time.h>
#include "Point.hpp"

#ifndef MAX_TEST_CASES
# define MAX_TEST_CASES 10000
#endif // MAX_TEST_CASES

#define LIMIT_TEST_CASES 10000

static inline float   randFloat(int num, int range){
    return ((float)(num / (float)(rand() % range)));
}

void    printTriangle ()
{
    std::cout << "*" << std::endl;
    std::cout << "*   Triangle Used For TEST_CASES:" << std::endl;
    std::cout << "*   -----------------------------" << std::endl;
    std::cout << "*" << std::endl;
    std::cout << "*    yAxis" << std::endl;
    std::cout << "*    ^" << std::endl;
    std::cout << "*    |         " << std::endl;
    std::cout << "*    |         " << std::endl;
    std::cout << "*   1|       /\\ b (1.0, 1.0)" << std::endl;
    std::cout << "*    |      /  \\" << std::endl;
    std::cout << "*    |     /    \\" << std::endl;
    std::cout << "*    |    /      \\" << std::endl;
    std::cout << "*    |   /        \\" << std::endl;
    std::cout << "*    |  /          \\" << std::endl;
    std::cout << "*    | /a (0.0, 0.0)\\ " << std::endl;
    std::cout << "*    |/______________\\ c (2.0, 0.0)" << std::endl;
    std::cout << "*    +----------------------------------> xAxis" << std::endl;
    std::cout << "*   0        1        2" << std::endl;
    std::cout << "*\n" << std::endl;

    return ;
}


void    testCases()
{
    Point   a(0.0, 0.0);
    Point   b(1.0, 1.0);
    Point   c(2.0, 0.0);
    float   xPoint[MAX_TEST_CASES];
    float   yPoint[MAX_TEST_CASES];
    int     range = 100;
    
    printTriangle();
    std::cout << " A(" << a.getX() << ", " << a.getY() << ") ";
    std::cout << "B(" << b.getX() << ", " << b.getY() << ") ";
    std::cout << "C(" << c.getX() << ", " << c.getY() << ")" << std::endl;
    std::cout << "------------------------ \n";
    srand(time(NULL));

    int _t, _f;
    _t = _f = 0;
    for(int i = 0; i < MAX_TEST_CASES; i++){
        xPoint[i] = randFloat(rand() % range, range);
        yPoint[i] = randFloat(rand() % range, range);
        #ifndef NDEBUG
            std::cout << "*\trand(" << xPoint[i] << ", " << yPoint[i] << ") : ";
        #endif // NDEBUG
        
        Point   point(xPoint[i], yPoint[i]);
        
        #ifdef SHOW_FALSE_CASES
            std::cout << "P(" << point.getX() << ", " << point.getY() << ") : ";
        #endif // SHOW_FALSE_CASES

        if (bsp(a, b, c, point) == 1)
        {
            #ifndef SHOW_FALSE_CASES
                std::cout << "P(" << point.getX() << ", " << point.getY() \
                    << ") : ";
            #endif // SHOW_FALSE_CASES 
            std::cout << "True" << std::endl; _t++;
        }
        else
        {
            #ifdef SHOW_FALSE_CASES
                std::cout << "False" << std::endl; 
            #endif // SHOW_FALSE_CASES
            _f++;
        }
        point.~Point();
    }
    std::cout << "TrueCases = " << _t << " | FalseCases = " << _f << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                     Normal Compilation:                                    */
/*       => make re CXXFLAGS+="-DNDEBUG"                                      */
/*                                                                            */
/*                   TestCases Compilation:                                   */
/*       => make re CXXFLAGS+="-DNDEBUG -DTEST_CASES"                         */
/*                                                                            */
/*                   Changing Number of TestCases Compilation:                */
/*       => make re CXXFLAGS+="-DNDEBUG -DTEST_CASES -DMAX_TEST_CASES=1000"   */
/*                                                                            */
/*                   TestCases With FalseCases Compilation:                   */
/*       => make re CXXFLAGS+="-DNDEBUG -DTEST_CASES -DSHOW_FALSE_CASES"      */
/*                                                                            */
/*                      Debug Compilation:                                    */
/*       => make re                                                           */
/*                                                                            */
/*   20 bits are used to represent the fractional part, 11 bits for integer   */
/* -------------------------------------------------------------------------- */

int main(void)
{
    Point   a(0.0, 1.0);
    Point   b(-5.99, 2.0);
    Point   c(-5.99, 0.0);
    Point   point(-5.989999, 1.99);

    #ifdef TEST_CASES
        std::cout << MAX_TEST_CASES << std::endl;
        if (MAX_TEST_CASES > LIMIT_TEST_CASES)
        {
            std::cerr << "Error: StackOverflow will occur: MAX_TEST_CASES limit is " \
                << LIMIT_TEST_CASES << std::endl;
            exit(1);
        }
        testCases();
    #endif // TEST_CASES

    #ifndef TEST_CASES
        std::cout << " A(" << a.getX() << ", " << a.getY() << ")  ";
        std::cout << "B(" << b.getX() << ", " << b.getY() << ") ";
        std::cout << "C(" << c.getX() << ", " << c.getY() << ") " ;
        std::cout << "P(" << point.getX() << ", " << point.getY() << ")" \
            << std::endl;
        std::cout << "--------- ----------- ----------- --------------\n";
        if (bsp(a, b, c, point) == 1)
            std::cout << "True" << std::endl;
        else
            std::cout << "False" << std::endl;
    #endif // TEST_CASES

    return 0;
}
