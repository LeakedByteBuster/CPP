#include "PhoneBook.hpp"
#include "utils.hpp"


/*
*   TODO:   Change attributes to private / get, set functions
*   TODO:   SEARCH + index
*   TODO:   Header for Class Contact || Contact's Attributes ==> private
*   TODO: Contacts    &PhoneBook::getContact(int i)? argument??????????
*/


#ifdef DEBUG_PROG
void    fill_data(PhoneBook &book){
    
    int i = 0;
    while (i < 8)
    {
        book.getContact(i).setFname("Lorem Ipsum");
        book.getContact(i).setLname("Lorem Ipsum");
        book.getContact(i).setPhoneNumber("212654879652");
        book.getContact(i).setDarkestSecrect("Lorem Ipsum");
        book.getContact(i).setNickname("Lorem Ipsum");
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
    while (std::getline(std::cin, cmd)){
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