#include "utils.hpp"
#include <iomanip>
#include "PhoneBook.hpp"
#include <string>

// *    Read value from input and store it by using setter [functor]
void    read_input(void (Contacts::*func)(std::string), Contacts &contact, \
        std::string prompt)
{
    std::string tmp;

    errorReadInputAgain:

        std::cout << HCYN << prompt << HWHT;
        std::getline(std::cin, tmp);
        if (std::cin.eof())
            exit(0);
        if (tmp.empty()){
            std::cout << HRED << "Error: empty field!\n" << HWHT;
            goto errorReadInputAgain;
        }
    //  Assign input of user to the corresponding variable
    (contact.*func)(tmp);
    return ;
}

// *    Prints a line of n length using '-' and '|' character
void    print_line(int widthSize, bool pipe)
{
    if (pipe == 1)
    {
        std::cout <<  "|";
        for (int i = 0; i < widthSize; i++){
            std::cout << "-";
        }
        std::cout << "|\n";
    }
    else
    {
        std::cout << " ";
        for (int i = 0; i < widthSize; i++){
            std::cout << "-";
        }
        std::cout << "-\n";
    }
    return ;
}

void    print_table_titles(int padMax, int padMin)
{
    padMin = 0;
    std::cout << "|" << std::right << std::setw(padMax) << "Index" << "|";
    std::cout << std::right << std::setw(padMax) << "FirstName" << "|";
    std::cout << std::right << std::setw(padMax) << "Last Name" << "|";
    std::cout << std::right << std::setw(padMax) << "Nickname" << "|";
    std::cout << "\n";
    return ;
}

static  std::string truncateString(std::string str)
{
    std::string truncated;

    truncated = str;
    if (!str.empty() && str.length() > 10){
        truncated = str.substr(0, 9);
        truncated += '.';
    }
    return (truncated);
}

void    print_data(PhoneBook &list, int columWidth, int padMin, int allPhoneBook)
{
    int i = 0;
    if (allPhoneBook == 0)
    {
        while (i < 8){
        
        std::cout << "|" << std::setw(columWidth) << std::right << i+1 << "|";
        std::cout << std::setw(columWidth) << std::right << truncateString(list.getContact(i).getFname()) << std::setw(padMin) << std::right << "|";
        std::cout << std::setw(columWidth) << std::right << truncateString(list.getContact(i).getLname()) << std::setw(padMin) << std::right << "|";
        std::cout << std::setw(columWidth) << std::right << truncateString(list.getContact(i).getNickname()) << std::setw(padMin) << std::right  << "|";
        std::cout << "\n";
        if (i < 7)
            print_line(columWidth * 4 + padMin * 3, 1);
        i++;
        }
    } 
    else
    {
        std::cout << "\n- First name: " << list.getContact(allPhoneBook-1%8).getFname() << "\n";
        std::cout << "- Last name: " << list.getContact(allPhoneBook-1%8).getLname() << "\n";
        std::cout << "- Nickname: " << list.getContact(allPhoneBook-1%8).getNickname() << "\n";
        std::cout << "- Phone number: " << list.getContact(allPhoneBook-1%8).getPhoneNumber() << "\n";
        std::cout << "- Darkest secrect: " << list.getContact(allPhoneBook-1%8).getDarkestSecrect() << "\n";
        std::cout << "\n";
    }
    return ;
}
