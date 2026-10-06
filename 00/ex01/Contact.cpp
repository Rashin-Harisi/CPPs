#include "Contact.hpp"


void Contact::setFirstName(std::string name){firstName = name;}
void Contact::setLastName(std::string name){lastName = name;}
void Contact::setNickName(std::string name){nickName = name;}
void Contact::setPhoneNumber(std::string number){phoneNumber = number;}
void Contact::setDarkSecret(std::string text){darkSecret = text;}

std::string Contact::getFirstName()const {return firstName;}
std::string Contact::getLastName()const {return lastName;}
std::string Contact::getNickName()const {return nickName;}
std::string Contact::getPhoneNumber()const {return phoneNumber;}
std::string Contact::getDarkSecret()const {return darkSecret;}

void Contact::show()
{
    std::cout << "Information\n";
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkSecret <<std::endl;
}
