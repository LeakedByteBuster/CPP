#include "PhoneBook.hpp"
#include <iomanip>

void    PhoneBook::add(Contacts &contact)
{
    first :
        std::cout << "* $> First name: ";
    std::getline(std::cin, contact.Fname);
    if (contact.Fname.empty()){
        std::cout << HRED << "Error: empty field\n" << HWHT;
        goto first;
    }
    return ;
}

void    PhoneBook::search(PhoneBook &list)
{
    int i = 0;

    std::cout << "\n" << std::setw(10) << "Index | ";
    std::cout << std::setw(10) << "FirstName  | ";
    std::cout << std::setw(10) << "LastName | ";
    std::cout << std::setw(10) << "Nickname |";
    std::cout << std::setw(10) <<"\n--------|-----\
-------|----------|----------|\n";
// ****************************

    while (i < 8 && !list.contact[i].Fname.empty()){
        std::cout << std::setw(8) << i+1 << "|" << std::setw(10) \
            << list.contact[i].Fname << " | ";
        std::cout << "\n";
        i++;
    }

// ****************************
    std::cout << "-----------------\
-------------------------\n";
    return ;
}

void    PhoneBook::exit_program()
{
    std::cout << "EXIT\n";
    return ;
}
        
Contacts    &PhoneBook::getContact(int i){
    return(contact[i]);
}
