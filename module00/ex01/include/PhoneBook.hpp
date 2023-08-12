#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>

# include "Contacts.hpp"

class PhoneBook{
private :
        Contacts contact[8];
public :
        Contacts &getContact(int i);
        void     add(Contacts &contact);
        void     search(PhoneBook &list);
};

// *    Read value from input and store it by using setter [functor]
void    read_input(void (Contacts::*func)(std::string), Contacts &contact, \
        std::string prompt);

void    print_line(int widthSize, bool pipe);

void    print_table_titles(int padMax, int padMin, bool printAllData);

void    print_data(PhoneBook &list, int padMax, int padMin);

#endif // PHONE_BOOK_HPP



