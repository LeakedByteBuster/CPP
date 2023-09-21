#include <stdlib.h>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define NUMBER_OF_ANIMALS 10

/* Testing Leaks */
#ifdef TEST_LEAKS
    void    lk()
    {
        system("leaks zoo");
        return ;
    }
#endif // TEST_LEAKS


#ifdef TESTS
    /* Loops Through NUMBER_OF_ANIMALS and prints NUMBER_OF_IDEAS strings*/
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

    /* Fill array of pointers with value "eat" */
    void    fillArray(std::string **arr)
    {
        int i = 0;

        while (arr[i]){
            for (int j = 0; j < NUMBER_OF_IDEAS; j++){
                    arr[i][j] = "eat...";
            }
            i++;
        }

        return ;
    }

    /* Fills Half of an array with Cats and the other half with Dog */
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
        /* Freeing all allocated pointers */
        for (int i = 0; i < NUMBER_OF_ANIMALS; i++){
            delete  zoo[i];
        }
    }
#endif // TEST

int main()
{
    #ifndef ASSIGN
        /* these two pointers are declared just to test virtual destructor
                "make re BUILD=build" to see them in action. */
        const Animal* pDog = new Dog();
        const Animal* pCat = new Cat();

        #ifdef TESTS
            /* Fills Half of an array with Cats and the other half with Dog */
            testUsingLoop();
        #endif // TESTS

        std::cout << std::endl;

    #else
        /* Creating two temporary pointers, then filling their std::string ideas */
        const Dog* dogToCopy = new Dog();
        const Animal* catToCopy = new Cat();
        std::cout << std::endl;
        std::string *p[3] = {dogToCopy->getIdeas(), catToCopy->getIdeas(), NULL};
        /* Fill Array of ideas && Print array of ideas of both objects */
        for (int i = 0; i < NUMBER_OF_IDEAS; i++){
            p[0][i] = "CopyMeA...";
            p[1][i] = "CopyMeB...";
            #ifndef STOP_SIMULATION
                std::cout << p[0][i];
                std::cout << p[1][i];
            #endif // STOP_SIMULATION
        }
        std::cout << std::endl << std::endl;

        /* Testing Deep Copy of Dog & Cat */
        const Animal* pDog = new Dog(*dogToCopy);
        Animal* pCat = new Cat((Cat &)(*catToCopy));
        /* Freeing temporary pointers */
        delete  catToCopy;
        delete  dogToCopy;
        /* Print Copied array of ideas of both objects */
        #ifndef STOP_SIMULATION
            std::string *p2[3] = {pDog->getIdeas(), pCat->getIdeas(), NULL};
            for (int i = 0; i < NUMBER_OF_IDEAS; i++){
                std::cout << p2[0][i];
                std::cout << p2[1][i];
            }
            std::cout << std::endl << std::endl;
        #endif // STOP_SIMULATION
    #endif // ASSIGN

    /* Freeing main pointers */
    delete pCat;
    delete pDog;

    /* Testing Leaks */
    #ifdef TEST_LEAKS
        atexit(lk);
    #endif // TEST_LEAKS

    return (0);
}