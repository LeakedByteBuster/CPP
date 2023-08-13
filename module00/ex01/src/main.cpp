#include "PhoneBook.hpp"
#include "utils.hpp"

#ifdef DEBUG_PROG
void    fill_data(PhoneBook &book){
    
    int i = 0;
    while (i < 8)
    {
        book.getContact(i).setFname("LoremIpsum");
        book.getContact(i).setLname("LoremIpsum");
        book.getContact(i).setPhoneNumber("212654879652");
        book.getContact(i).setDarkestSecrect("LoremIpsum");
        book.getContact(i).setNickname("LoremIpsum");
        i++;
    }
    return ;
}
#endif // DEBUG_PROG

// *    Prompt user to enter an index then print it, if the input is correct
static void askForIndexAndPrintIt(PhoneBook &contacts)
{
    std::string userInput;
    int     x = -1;
    bool    WrongInput = 0;

    while (1){
        // *    read line for STDIN
        std::cout << HCYN << "* > Enter index: " << HWHT;
        std::getline(std::cin, userInput);
        if (std::cin.eof())
            return ;
        // *    Check if input is free from errors
        for (unsigned long i = 0; i < userInput.length(); i++) {
            if (std::string("0123456789").find(userInput[i]) == std::string::npos) {
                WrongInput = 1;
                break ;
            }
        }
        // *    Print corresponding index
        if (WrongInput == 0)
            x = std::atoi(userInput.data());
        if (x > 0 && x <= 8 && WrongInput == 0){
            contacts.search(contacts, x);
            return ;
        }
        // *    print error
        else if (!userInput.empty()) {
            std::cout << HRED << "Error: index "<< userInput << " not found!\n" << HWHT;
        }
        WrongInput = 0;
    }
    return ;
}

int main()
{
    PhoneBook   contacts;
    std::string  userInput;

    welcome_message();

#ifdef DEBUG_PROG
    fill_data(contacts);
#endif // DEBUG_PROG

    int i = 0;
    while (std::getline(std::cin, userInput)){
        if (userInput == "ADD") {
            Contacts &tmp = contacts.PhoneBook::getContact(i%8);
            contacts.add(tmp);
            i++;
        }
        else if (userInput == "SEARCH") {
            contacts.search(contacts, 0);
            askForIndexAndPrintIt(contacts);
        } 
        else if (userInput == "EXIT") {
            break ;
        }
        std::cout << "* $> ";
    }
    std::cout << RESET;
    return (0);
}