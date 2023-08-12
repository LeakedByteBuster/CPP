#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <string>

# define LIST \
    X(Fname) \
    X(Lname) \
    X(nickname) \
    X(PhoneNumber) \
    X(DarkSecrect)

class Contacts{
private :
        #define X(name) std::string name;
                LIST
        #undef LIST
public :
        //  *** Value Setter Methods ***
        void  setFname(std::string Fname);
        void  setLname(std::string Lname);
        void  setNickname(std::string nickname);
        void  setPhoneNumber(std::string PhoneNumber);
        void  setDarkestSecrect(std::string DarkSecrect);

        //  *** Value Getter Methods ***
        std::string  getFname();
        std::string  getLname();
        std::string  getNickname();
        std::string  getPhoneNumber();
        std::string  getDarkestSecrect();
};

#endif // CONTACTS_HPP