/*
*    $>./megaphone "shhhhh... I think the students are asleep..."
*       SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
*    $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
*       DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
*    $>./megaphone
*       * LOUD AND UNBEARABLE FEEDBACK NOISE *
*    $>
*/

#include <iostream>
#include <string>
#include <locale>

int main(int ac, char **av)
{
    if (ac > 1){
        // object initialized with the default locale.
        std::locale loc;
        std::string str;
        int i = -1;

        av++;
        while (av[++i]){
            str = av[i];
            for (std::string::size_type i = 0; i < str.length(); ++i) //  size_type = size_t;
                std::cout << std::toupper(str[i], loc);
        }
        std::cout << "\n";
        return (0);
    }
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return (0);
}