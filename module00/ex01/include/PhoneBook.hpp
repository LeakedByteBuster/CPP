#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>
# include <string>
# include "Contacts.hpp"

class PhoneBook{
private :
        Contacts contact[8];
public :
        Contacts &getContact(int i);
        void     add(Contacts &contact);
        void     search(PhoneBook &list);
};

#endif // PHONE_BOOK_HPP



