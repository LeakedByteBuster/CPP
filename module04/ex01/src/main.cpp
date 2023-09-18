#include <stdlib.h>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

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
    #ifndef STOP_SIMULATION
        void    printArr(Animal **p)
        {
            for (int i = 0; i < NUMBER_OF_ANIMALS; i++){
                for (int j = 0; j < NUMBER_OF_IDEAS; j++){
                    std::cout << p[i]->getIdeas()[j];
                }
                std::cout << std::endl;
            }
            return ;
        }
    #endif // STOP_SIMULATION

    void    fillArray(std::string **arr)
    {
        int i = 0;

        while (arr[i]){
            for (int j = 0; j < NUMBER_OF_IDEAS; j++){
                #ifndef ASSIGN
                    arr[i][j] = "eat...";
                #else
                    arr[i][j] = "Assign...";
                #endif // ASSIGN
            }
            i++;
        }

        return ;
    }

    void    testUsingLoop()
    {
        Animal* zoo[NUMBER_OF_ANIMALS];

        if ((NUMBER_OF_ANIMALS % 2) != 0)
            return ;
        for (int i = 0; i < NUMBER_OF_ANIMALS; i++){
            zoo[i] = new Cat();
            i++;
            zoo[i] = new Dog();
            fillArray(((std::string *[]){zoo[i-1]->getIdeas(), \
                zoo[i]->getIdeas(), NULL}));
        }
        #ifndef STOP_SIMULATION
            printArr(zoo);
        #endif // STOP_SIMULATION
        for (int i = 0; i < NUMBER_OF_ANIMALS; i++){
            delete  zoo[i];
        }
    }
#endif // TEST

int main()
{
    #ifndef ASSIGN
        const Animal* pDog = new Dog();
        const Animal* pCat = new Cat();
    #else
        const Animal* pD = new Dog();
        const Animal* pC = new Cat();

        const Animal* pDog = new Dog((Dog &)(*pD));
        // fillArray(&pDog);
        const Animal* pCat = new Cat((Cat &)*pC);
        // printArr(&pCat);
    #endif // ASSIGN

    #ifdef TESTS
        testUsingLoop();
    #endif // TESTS

    #ifdef ASSIGN
        delete  pC;
        delete  pD;
    #endif // ASSIGN
    delete pCat;
    delete pDog;

    /* Testing Leaks */
    #ifdef TEST_LEAKS
        atexit(lk);
    #endif // TEST_LEAKS

    return (0);
}