#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include <iostream>
# include <string>
# include "utils.hpp"

/*
*   The contact fields are: first name, last name, nickname, phone number, and
        darkest secret. A saved contact can’t have empty fields.
*/
class Contacts{
private :
public :
        #define X(name) std::string name;
                LIST
        #undef LIST
};

class PhoneBook{
private :
        Contacts contact[8];
public :
        Contacts &getContact(int i);
        void     add(Contacts &contact);
        void     search(PhoneBook &list);
        void     exit_program();
};

#endif // PHONE_BOOK_H



