#include <stdlib.h>
#include "Dog.hpp"
#include "Cat.hpp"

#ifdef  TESTS
#   define ANIMAL_NUMBER 10
#endif  // TESTS

#ifdef TEST_LEAKS
    void    lk()
    {
        system("leaks zoo");
        return ;
    }
#endif // TEST_LEAKS


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    #ifdef  TESTS
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        Animal* zoo[ANIMAL_NUMBER];
        for (int i = 0; i < ANIMAL_NUMBER; i++){
            if (i + 3 < ANIMAL_NUMBER){
                
                std:: cout << i << ". ";
                zoo[i] = new Cat();
                zoo[i++]->makeSound();
                delete zoo[i - 1];

                std:: cout << i << ". ";
                zoo[i] = new Dog();
                zoo[i++]->makeSound();
                delete zoo[i - 1];

                std:: cout << i << ". ";
                zoo[i] = new Animal();
                zoo[i]->makeSound();
                delete zoo[i];
            }
        }
    #endif // TESTS

    delete meta;
    delete j;
    delete i;

    #ifdef TEST_LEAKS
        atexit(lk);
    #endif // TEST_LEAKS

    return (0);
}