#include <iostream> // cout
#include <cstdlib> // rand() && srand
#include <time.h> // time
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*
*   0. dynamic_cast is used at run time to find out correct down-cast.
*   1: Need at least one virtual function in base class.
*   2: If the cast is successful, dynamic_cast returns a value of type new_type. 
*   3: If the cast fails and new_type is a pointer type, it returns a null pointer of that type.
*   4: If the cast fails and new_type is a reference type, it throws an exception that matches a handler of type std::bad_cast.
*   
*   BOTTOM LINE:
*   1. work only on polymorphic base class (at least one virtual function in base class) because it uses this information to decide about wrong down-cast.
*   2. it is used for up-cast (D to B) and down-cast (B to D), but it is mainly used for correct downcast.
*   3. using this cast has run time overhead, because it checks object types at run time using RTTI (Run Time Type Information).
*   4. if we are sure that we will never cast to wrong object then we should always avoid this cast and use static_cast.
*/

/* [UPCAST] randomly instanciates A, B or C as a base pointer*/
Base    *generate(void)
{
    Base    *b = NULL;
    A* Aptr = new A;
    B* Bptr = new B;
    C* Cptr = new C;

    srand(time(0));
    int choice = rand() % 3;
    switch (choice)
    {
    case 0:
        
        std::cout << " [GENERATED] Aptr is returned\n";
        delete Bptr;
        delete Cptr;
        b = dynamic_cast<Base *>(Aptr);
        return (b);

    case 1:
        
        std::cout << " [GENERATED] Bptr is returned\n";
        delete Aptr;
        delete Cptr;
        b = dynamic_cast<Base *>(Bptr);
        return (b);

    case 2:
        
        std::cout << " [GENERATED] Cptr is returned\n";
        delete Aptr;
        delete Bptr;
        b = dynamic_cast<Base *>(Cptr);
        return (b);
    }
    return (b);
}

/* [DOWNCAST] prints the actual type of the object pointed to by p: "A", "B" or "C" */
void    identify(Base *b)
{
    A   *Aptr = dynamic_cast<A*>(b);
    B   *Bptr = dynamic_cast<B*>(b);
    C   *Cptr = dynamic_cast<C*>(b);

    int i = (Aptr != NULL) * 1 \
            + (Bptr != NULL) * 2 \
            + (Cptr != NULL) * 3;

    switch (i)
    {
    case 1 : /* Aptr */
        std::cout << " [POINTER] Type in base pointer is (A)\n";
        delete b;
        break;

    case 2 : /* Bptr */
        std::cout << " [POINTER] Type in base pointer is (B)\n";
        delete b;
        break;

    case 3 : /* Cptr */
        std::cout << " [POINTER] Type in base pointer is (C)\n";
        delete b;
        break;    
    default:
        break;
    }
    return ;
}

/* [DOWNCAST] prints the actual type of the object pointed to by p: "A", "B" or "C" */
void    identify(Base &b)
{
    try {
        A   &Aptr = dynamic_cast<A&>(b);
        std::cout << " [REFERENCE] Type in base pointer is (A)\n";
        // Dummy operation to avoid warning and respect subject requirement
        Aptr = dynamic_cast<A&>(b); 
        return ;

    } catch (std::exception &e) {
        try {
            B   &Bptr = dynamic_cast<B&>(b);
            std::cout << " [REFERENCE] Type in base pointer is (B)\n";
            // Dummy operation to avoid warning and respect subject requirement
            Bptr = dynamic_cast<B&>(b);
            return ;

        } catch (std::exception &e) {
            try {
                C   &Cptr = dynamic_cast<C&>(b);
                std::cout << " [REFERENCE] Type in base pointer is (C)\n";
                // Dummy operation to avoid warning and respect subject requirement
                Cptr = dynamic_cast<C&>(b);
                return ;

            } catch (std::exception &e) {
                std::cout << "Unknown type\n";
            }
        }
    }
    return ;
}

int main()
{
    Base *b = generate();
    Base *b1 = (generate()); /* Its only purpose is for freeing the pointer */
    Base &b2 = *b1;
    identify(b);
    identify(b2);
    delete b1;
    return (0);
}