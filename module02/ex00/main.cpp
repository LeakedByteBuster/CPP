#include <iostream>
#include "Fixed.hpp"

void    printBinary()
{
    //***************************************************************************//

    int  x = 5;

    int  n = sizeof(int) * 8 -1;
    for (; n >= 0;n--){
    // bit = x & (1 << n);
    printf("%d", (x >> n) & 1);
    if (n%8 == 0)
        printf(" ");
    }
    puts("\n");
//***************************************************************************//

    // x = (1 << 1);
    printf("x = %d\n", x);

    // n = sizeof(int) * 8 -1;
    // for (int i = n; i > 7; i--){
    //     x &= ~(1 << i);
    // }

//***************************************************************************//
    n = sizeof(int) * 8 -1;
    for (; n >= 0;n--){
    // bit = x & (1 << n);
    printf("%d", (x >> n) & 1);
    if (n%8 == 0)
        printf(" ");
    }
    puts("\n");

    printf("x = %d\n", x);

//***************************************************************************//


    // printf("left_shift: %d\n", x << 1);
    // printf("right_shift: %d\n", x >> 1);

    // int c = x << 24;
    // printf("right_shift: %c \n", c );

    // n = sizeof(int) * 8 -1;
    // for (; n >= 0;n--){
    //     printf("%d", (c >> n) & 1);
    //     if (n%8 == 0)
    //         printf(" ");
    // }
    return ;
}

int main()
{

    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    #ifndef NDEBUG
        printBinary();
    #endif // NDEBUG

    return 0;
}

/*
    Default constructor called
    Copy constructor called
    Copy assignment operator called
    getRawBits member function called
    Default constructor called
    Copy assignment operator called
    getRawBits member function called
    getRawBits member function called
    0
    getRawBits member function called
    0
    getRawBits member function called
    0
    Destructor called
    Destructor called
    Destructor called
*/