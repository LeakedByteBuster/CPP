#include "Array.hpp"

#if defined(LEAKS)
    void    lk(){
        system("leaks array");
    }
#endif // LEAKS

template <typename Y, typename L>
void    print(Array<Y> &b, Array<Y> &c, L &size) {

    std::cout << "b size = " << b.size() << "\n";
    std::cout << "c size = " << c.size() << "\n";

    std::cout << "b\tc\n----\t----\n" << std::fixed;
    for (int i = 0; i < size; i++){
        std::cout << b[i] << "\t" << c[i];
        std::cout << "\n";
    }
}

int main(void) {

    int    size = 5;

    #if CHAR
        Array<char> b(size); /*  Call parameterized constructor  */ 
    #elif DOUBLE 
        Array<double> b(size); /*  Call parameterized constructor  */ 
    #elif STRING 
        Array<std::string> b(size); /*  Call parameterized constructor  */ 
    #else 
        Array<int> b(size); /*  Call parameterized constructor  */

    #endif // Creating B array

    for (int i = 0; i < size; i++){
        #if STRING
            b[i] = "First";
        #elif CHAR
            b[i] = 'a';
        #else
            b[i] = i;
        #endif // STRING
    }

    #if CHAR
        Array<char> c(b); /* Call copy constructor */ 
    #elif DOUBLE 
        Array<double> c(b); /* Call copy constructor */ 
    #elif STRING 
        Array<std::string> c(b); /* Call copy constructor */ 
    #else 
        Array<int> c(b); /* Call copy constructor */
    #endif // Creating C array

    /* Printing the two arrays */
    print(b, c, size);

    /* Changing a value in b array */
    for (int i = 0; i < size; i++){
        #if STRING 
            b[i] = "Second";
        #elif CHAR
            b[i] = 'z';
        #else
            b[i] = i + 100;
        #endif // STRING
    }
    std::cout << "\n";
    print(b, c, size);


    #if defined(LEAKS)
        atexit(lk);
    #endif // LEAKS
    return (0);
}