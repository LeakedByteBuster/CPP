#include <stdlib.h>
#include "Dog.hpp"
#include "Cat.hpp"

#ifdef WRONG_CLASSES
#   include "WrongCat.hpp"
#endif // WRONG_CLASSES

#ifdef  TESTS
#   define NUMBER_OF_ANIMALS 10
#endif  // TESTS

#ifdef TEST_LEAKS
    void    lk()
    {
        system("leaks zoo");
        return ;
    }
#endif // TEST_LEAKS

#ifdef TESTS
void    testUsingLoop()
{
    #ifndef WRONG_CLASSES
        Animal* zoo[NUMBER_OF_ANIMALS];
    #else
        WrongAnimal* zoo[NUMBER_OF_ANIMALS];
    #endif // WRONG_CLASSES

    for (int i = 0; i < NUMBER_OF_ANIMALS; i++){
        if (i + 3 < NUMBER_OF_ANIMALS){
            
            std:: cout << i + 1 << ". ";
            #ifndef WRONG_CLASSES
                zoo[i] = new Cat();
            #else
                zoo[i] = new WrongCat();
            #endif // WRONG_CLASSES
            zoo[i++]->makeSound();
            delete zoo[i - 1];

            #ifndef WRONG_CLASSES
                std:: cout << i + 1 << ". ";
                zoo[i] = new Dog();
                zoo[i++]->makeSound();
                delete zoo[i - 1];
            #endif // WRONG_CLASSES

            std:: cout << i + 1 << ". ";
            #ifndef WRONG_CLASSES
                zoo[i] = new Animal();
            #else
                zoo[i] = new WrongAnimal();
            #endif // WRONG_CLASSES
            zoo[i]->makeSound();
            delete zoo[i];
        }
    }
}
#endif // TEST

int main()
{
    /* Declaring and initializing pointers */
    #ifdef WRONG_CLASSES
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();

    #elif ASSIGN
        const Animal* a = new Animal();
        const Dog* d = new Dog();
        const Cat* c = new Cat();

        const Animal* meta = new Animal(*a);
        const Animal* j = new Dog(*d);
        const Animal* i = new Cat(*c);

    #else
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

    #endif // WRONG_CLASSES

    /* Printing the sound of each animal */
    i->makeSound();
    #ifndef WRONG_CLASSES
        j->makeSound();
    #endif // WRONG_CLASSES
    meta->makeSound();

    /* Testing allocation and subType polymorphism */
    #ifdef  TESTS
        #ifndef WRONG_CLASSES
            std::cout << j->getType() << " " << std::endl;
        #endif // WRONG_CLASSES
        std::cout << i->getType() << "\n" << std::endl;
        testUsingLoop();
    #endif // TESTS

    /* Freeing the pointers */
    delete i;
    #ifndef WRONG_CLASSES
        delete j;
    #endif // WRONG_CLASSES
    delete meta;

    #ifdef ASSIGN
        delete c;
        #ifndef WRONG_CLASSES
            delete d;
        #endif // WRONG_CLASSES
        delete a;
    #endif //ASSIGN

    /* Testing Leaks */
    #ifdef TEST_LEAKS
        atexit(lk);
    #endif // TEST_LEAKS

    return (0);
}