#if !defined(SERIALIZER_HPP)
#define SERIALIZER_HPP

#include <cstdint> // uintptr_t
#include "Data.hpp"

class Serializer {
private :
    Serializer();

public :
    Serializer(Serializer &);
    Serializer& operator=(Serializer &);
    virtual ~Serializer() = 0;

    static uintptr_t    serialize(Data* ptr);
    static Data*        deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP