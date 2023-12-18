#include <iostream>
#include "Serializer.hpp"

/*
* 1. reinterpret_cast can perform dangerous conversions because it can typecast any pointer to any other pointer.
* 2. reinterpret_cast is used when you want to work with bits.
* 3. The result of a reinterpret_cast cannot safely be used for anything other than being cast back to its original type.
* 4. we should be very careful when using this cast.
* 5. if we use this type of cast then it becomes non-portable product.
*/

int main()
{
    Data    p;

    p.c = '1';
    p.i = 1;
    std::cout << " Original State : char = " << p.c << " | int  = " << p.i << "\n";
    uintptr_t   serial = Serializer::serialize(&p);
    std::cout << " After Serialization : " << serial << "\n";
    Data        *deserial = Serializer::deserialize(serial);
    std::cout << " After Deserialization : char = " << deserial->c << " | int  = " << deserial->i << "\n";

    return (0);
}

