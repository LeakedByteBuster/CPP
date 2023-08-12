#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iomanip>

// *    Gets contact at index [i]
Contacts    &PhoneBook::getContact(int i){
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
void    PhoneBook::search(PhoneBook &list)
{
    int padMax = 20; // *   Column width
    int padMin = 3; // *    pipe '|' character width

    // *    Change prompt to the blue color
    std::cout << HCYN;
    
    // *    Prints first line
    print_line(padMax * 4 + padMin * 4 -3, 0);

    // *    Prints first table's row [Titles]
    print_table_titles(padMax, padMin, 0);

    // *    Prints middle line
    print_line(padMax * 4 + padMin * 4 -2, 1);
    
    // *    Prints Index Column, firstName Column, lastName column, nickName column, respectively.
    print_data(list, padMax, padMin);

    // *    Prints last line
    print_line(padMax * 4 + padMin * 4 -3, 0);

    // *    Change prompt back to the white color
    std::cout << HWHT;
    return ;
}