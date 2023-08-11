#ifndef UTILS_H
#define UTILS_H

#include "PhoneBook.hpp"

# define HBLK "\e[1;90m"
# define HRED "\e[1;91m"
# define HGRN "\e[1;92m"
# define HYEL "\e[1;93m"
# define HBLU "\e[1;94m"
# define HMAG "\e[1;95m"
# define HCYN "\e[1;96m"
# define HWHT "\e[1;97m"
# define RESET "\x1b[0m"

class   Contacts;
class   PhoneBook;

# define LIST \
    X(Fname) \
    X(Lname) \
    X(nickname) \
    X(PhoneNumber) \
    X(Dark_Secrect)

void    add(Contacts &contact);
void    search(PhoneBook &list);
void    exit_program();

#endif // UTILS_H