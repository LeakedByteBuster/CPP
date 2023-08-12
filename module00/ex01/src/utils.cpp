#include <iostream>
#include "utils.hpp"

void welcome_message(){
    std::cout << "(\n";
    std::cout << "\'\\ \n";
    std::cout << " \\'\\     __________  \n";
    std::cout << " / '|   ()_________)\n";
    std::cout << " \\ '/    \\ ~~~~~~~~ \\\n";
    std::cout << "   \\       \\ ~~~~~~   \\\n";
    std::cout << "   ==).      \\__________\\\n";
    std::cout << "  (__)       ()__________)\n\n";
    std::cout << HCYN << "Commands: \n- ADD\n- SEARCH | SEARCH <index>\n- EXIT\n\n" << RESET;
    std::cout << HWHT << "* $> ";
    return ;
}
