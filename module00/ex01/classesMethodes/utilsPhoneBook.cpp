// #include "Contacts.hpp"
#include "utils.hpp"
#include <iomanip>
#include "PhoneBook.hpp"

// *    Read value from input and store it by using setter [functor]
void    read_input(void (Contacts::*func)(std::string), Contacts &contact, \
        std::string prompt){
    
    std::string tmp;

    errorReadInputAgain:
    std::cout << HCYN;
        std::cout << prompt;
        std::cout << HWHT;
        std::getline(std::cin, tmp);
        if (std::cin.eof())
            exit(0);
        if (tmp.empty()){
            std::cout << HRED << "Error: empty field!\n" << HWHT;
            goto errorReadInputAgain;
        }
    //  calls the setter to assign tmp to the corresponding variable
    (contact.*func)(tmp);
    return ;
}

// *    Prints a line of n length using '-' and '|' character
void    print_line(int widthSize, bool pipe){
    
    if (pipe)
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

void    print_table_titles(int padMax, int padMin, bool printAllData){

    std::cout << "|" << std::right << std::setw(padMax) << "Index" << std::setw(padMin) << " | ";
    std::cout << std::setw(padMax) << "FirstName" << std::setw(padMin) << " | ";
    std::cout << std::setw(padMax) << "LastName" << std::setw(padMin) << " | ";
    std::cout << std::setw(padMax) << "Nickname" << std::setw(padMin) << " | ";
    if (printAllData){
        std::cout << std::setw(padMax) << "Phone Number" << std::setw(padMin) << " | ";
        std::cout << std::setw(padMax) << "LastName" << std::setw(padMin) << " | ";
    }
    std::cout << "\n";
    return ;
}

void    print_data(PhoneBook &list, int padMax, int padMin){
    int i = 0;
    padMin = 0;
    while (i < 8){
        std::cout << "|" << std::setw(padMax) << std::right << i+1 << " | ";
        std::cout << std::setw(padMax) << std::left << list.getContact(i).getFname()  << " | ";
        std::cout << std::setw(padMax) << std::left << list.getContact(i).getLname()  << " | ";
        std::cout << std::setw(padMax) << std::left << list.getContact(i).getNickname()  << " | ";
        std::cout << "\n";
        i++;
    }
    return ;
}