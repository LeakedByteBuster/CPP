#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iomanip>
#include <string>
#include <sys/ioctl.h>

// *    Gets contact at index [i]
Contacts    &PhoneBook::getContact(int i)
{
    return(contact[i]);
}

// *   Get first name, last name, nickname, phone number, and darkest secret from user
void    PhoneBook::add(Contacts &contact)
{
    read_input(&Contacts::setFname, contact, "* $> First name: ");
    read_input(&Contacts::setLname, contact, "* $> Last name: ");
    read_input(&Contacts::setNickname, contact, "* $> Nickname: ");
    read_input(&Contacts::setPhoneNumber, contact, "* $> Phone number: ");
    read_input(&Contacts::setPhoneNumber, contact, "* $> Darkest Secret: ");
    return ;
}

// *    Prints the list of contacts, and looks for a specific contact
void    PhoneBook::search(PhoneBook &list, int printIndex)
{
    int padMax = 10; // *   Column width
    int padMin = 1; // *    pipe '|' character width

    int tableWidth = padMax * 4 + padMin * 3;
    if (printIndex != 0){
        std::cout << HYEL;
        print_data(list, padMax, padMin, printIndex);
        std::cout << HWHT;
        return ;
    }
    // *    Change prompt to the blue color
    std::cout << HCYN;
    
    // *    Prints first line
    print_line(tableWidth-1, 0);

    // *    Prints first table's row [Titles]
    print_table_titles(padMax, padMin);

    // *    Prints middle line
    print_line(tableWidth, 1);
    
    // *    Prints Index Column, firstName Column, lastName column, nickName column, respectively.
    print_data(list, padMax, padMin, printIndex);

    // *    Prints last line
    print_line(tableWidth-1, 0);

    // *    Change prompt back to the white color
    std::cout << HWHT;
    return ;
}