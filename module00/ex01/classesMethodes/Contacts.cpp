#include "Contacts.hpp"
#include "iostream"

//  *** Value Getters ***
std::string  Contacts::getFname(){
    return (this->Fname);
}

std::string  Contacts::getLname(){
    return (this->Lname);
}

std::string  Contacts::getNickname(){
    return (this->nickname);
}

std::string  Contacts::getPhoneNumber(){
    return (this->PhoneNumber);
}

std::string  Contacts::getDarkestSecrect(){
    return (this->DarkSecrect);
}

//  *** Value Setters ***
void    Contacts::setFname(std::string Fname){
    this->Fname = Fname;
}

void    Contacts::setLname(std::string Lname){
    this->Lname = Lname;
}

void    Contacts::setNickname(std::string nickname){
    this->nickname = nickname;
}

void    Contacts::setPhoneNumber(std::string PhoneNumber){
    this->PhoneNumber = nickname;
}

void    Contacts::setDarkestSecrect(std::string DarkSecrect){
    this->DarkSecrect = DarkSecrect;
}
