#include "PhoneBook.hpp"
#include <sstream>

static void welcome_message(){
    std::cout << "                                                                        (\n";
    std::cout << "                                                                        \'\\ \n";
    std::cout << ".------..------..------..------..------..------..------..------..------. \\'\\     __________           \n";
    std::cout << "|P.--. ||H.--. ||O.--. ||N.--. ||E.--. ||B.--. ||O.--. ||O.--. ||K.--. | / '|   ()_________)          \n";
    std::cout << "| :/\\: || :/\\: || :/\\: || :(): || (/\\) || :(): || :/\\: || :/\\: || :/\\: | \\ '/    \\ ~~~~~~~~ \\         \n";
    std::cout << "| (__) || (__) || :\\/  || ()() || :\\/  || ()() || :\\/  || :\\/  || :\\/  |   \\       \\ ~~~~~~   \\       \n";
    std::cout << "| '--'P|| '--'H|| '--'O|| '--'N|| '--'E|| '--'B|| '--'O|| '--'O|| '--'K|   ==).      \\__________\\     \n";
    std::cout << "`------'`------'`------'`------'`------'`------'`------'`------'`------'  (__)       ()__________)    \n\n";
    std::cout << HRED << "Commands: \n- ADD\n- SEARCH | SEARCH <index>\n- EXIT\n\n" << RESET;
    std::cout << HWHT << "* $> ";
    return ;
}


/*
*   TODO:   ==> ADD ==> Ctrl+a || Infinite loop
*   TODO:   Change attributes to private / get, set functions
*   TODO:   SEARCH command + index
*   TODO:   Header for Class Contact
*/

#ifdef DEBUG_PROG
void    fill_data(PhoneBook &book){
    
    int i = 0;
    while (i < 8)
    {
        book.getContact(i).Fname = "Lorem Ipsum";
        book.getContact(i).Lname = "Lorem Ipsum";
        book.getContact(i).PhoneNumber = "212654879652";
        book.getContact(i).Dark_Secrect = "Lorem Ipsum";
        book.getContact(i).nickname = "Lorem Ipsum";
        i++;
    }
    return ;
}
#endif // DEBUG_PROG

int main(){
    std::string  cmd;
    PhoneBook   contacts;
    int i = 0;

#ifdef DEBUG_PROG
    fill_data(contacts);
#endif // DEBUG_PROG

    welcome_message();
    while ((std::getline(std::cin, cmd))){
        // std::stringstream ss;
        if (cmd == "ADD") {
            Contacts &tmp = contacts.PhoneBook::getContact(i%8);
            contacts.add(tmp);
            i++;
        } else if (cmd == "SEARCH") {
            contacts.search(contacts);
        } else if (cmd == "EXIT") {
            break ;
        }
        std::cout << "* $> ";
    }
    std::cout << RESET;
    return (0);
}