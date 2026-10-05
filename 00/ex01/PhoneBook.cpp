#include "PhoneBook.hpp"

int PhoneBook::getIndex(){return index;}

PhoneBook::PhoneBook()
{
    capacity = 0;
    index = 0;
}

void PhoneBook::add()
{
    Contact new_contact;
    std::string temp;

    do
    {
        std::cout << "Please Enter First Name:";
        if (!std::getline(std::cin,temp)) return;
        if (temp.empty()) std::cout << "Field cannot be empty!\n";
    } while (temp.empty());
    new_contact.setFirstName(temp);
    do
    {
        std::cout << "Please Enter Last Name:";
        if (!std::getline(std::cin,temp)) return;
        if (temp.empty()) std::cout << "Field cannot be empty!\n";        
    } while (temp.empty());
    new_contact.setLastName(temp);
    do
    {
        std::cout << "Please Enter Nick Name:";
        if (!std::getline(std::cin,temp)) return;
        if (temp.empty()) std::cout << "Field cannot be empty!\n";        
    } while (temp.empty());
    new_contact.setNickName(temp);
    do
    {
        std::cout << "Please Enter Phone Number:";
        if (!std::getline(std::cin,temp)) return;
        if (temp.empty()) std::cout << "Field cannot be empty!\n";        
    } while (temp.empty());
    new_contact.setPhoneNumber(temp);
    do
    {
        std::cout << "Please Enter the Dark Secret:";
        if (!std::getline(std::cin,temp)) return;
        if (temp.empty()) std::cout << "Field cannot be empty!\n";        
    } while (temp.empty());
    new_contact.setDarkSecret(temp);
    contacts[index] = new_contact;
    index++;
    if (index == 8) index = 0;
    if (capacity < 8) capacity++;
}

void PhoneBook::search()
{}