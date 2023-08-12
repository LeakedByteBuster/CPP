#include "PhoneBook.hpp"
#include <iomanip>
#include "utils.hpp"

/*
*   first name, last name, nickname, phone number, and darkest secret
*/
void    PhoneBook::add(Contacts &contact)
{
    std::string tmp;

    first :
        std::cout << "* $> First name: ";
        std::getline(std::cin, tmp);
        if (std::cin.eof())
            exit(0);
        if (tmp.empty()){
            std::cout << HRED << "Error: empty field\n" << HWHT;
            goto first;
        }
        contact.setFname(tmp);
    return ;
}
// *    Prints the list of contacts, and looks for a specific contact
void    PhoneBook::search(PhoneBook &list)
{
    int i = 0;
    int padMax = 40; // Column width
    int padMin = 3; // pipe '|' character width

    // *    Prints first line
    int widthSize = padMax * 4 + padMin * 4 -2;
    std::cout << HBLU;
    for (int i = 0; i < widthSize; i++){
        std::cout << "-";
    }
    std::cout << "-\n";

    // *    Prints first table's row
    std::cout << "|" << std::right << std::setw(padMax) << "Index" << std::setw(padMin) << " | ";
    std::cout << std::setw(padMax) << "FirstName" << std::setw(padMin) << " | ";
    std::cout << std::setw(padMax) << "LastName" << std::setw(padMin) << " | ";
    std::cout << std::setw(padMax) << "Nickname" << std::setw(padMin) << " | \n";

    // *    Prints mid line
    std::cout <<  "|";
    for (int i = 0; i < widthSize; i++){
        std::cout << "-";
    }
    std::cout << "|\n";
    
    // *    Prints Index Column, firstName Column, lastName column, nickName column, respectively.
    while (i < 8){
        std::cout << "|" << std::setw(padMax) << std::right << i+1 << " | ";
        std::cout << std::setw(padMax) << std::left << list.contact[i].getFname()  << " | ";
        std::cout << std::setw(padMax) << std::left << list.contact[i].getLname()  << " | ";
        std::cout << std::setw(padMax) << std::left << list.contact[i].getNickname()  << " | ";
        std::cout << "\n";
        i++;
    }

    // *    Prints last line
    for (int i = 0; i < widthSize; i++){
        std::cout << "-";
    }
    std::cout << "-\n";
    std::cout << HWHT;
    return ;
}

// *    Gets contact i
Contacts    &PhoneBook::getContact(int i){
    return(contact[i]);
}
