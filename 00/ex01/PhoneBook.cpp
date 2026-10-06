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

void display(std::string index, std::string firstName, std::string lastName, std::string nickName)
{
    std::cout << std::right
              << std::setw(10) << index << '|'
              << std::setw(10) << firstName << '|'
              << std::setw(10) << lastName << '|'
              << std::setw(10) << nickName << '\n';
}

void PhoneBook::search()
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string temp;

    if (capacity == 0)
    {
        std::cout << "The Phonebook's List Is Empty!\n";
        return;
    }
    display("index", "First Name", "Last Name", "Nickname");
    for (int i = 0; i < capacity ; i++)
    {
        firstName = contacts[i].getFirstName();
        if (firstName.size() > 10)
        {
            temp = firstName.substr(0,9);
            firstName = temp + '.';
        }
        lastName = contacts[i].getLastName();
        if (lastName.size() > 10)
        {
            temp = lastName.substr(0,9);
            lastName = temp + '.';
        }
        nickName = contacts[i].getNickName();
        if (nickName.size() > 10)
        {
            temp = nickName.substr(0,9);
            nickName = temp + '.';
        }
        std::ostringstream stream;
        stream << i;
        std::string indexText = stream.str();
        display(indexText, firstName, lastName, nickName);
    }
    bool valid;
    valid = false;
    do
    {
        std::cout << "Please enter the index to see the complete information:";
        if (!std::getline(std::cin, temp)) return;
        std::istringstream stream(temp);
        int number;
        char extra;
        if (!(stream >> number)) std::cout << "Invalid Number!\n";
        else if (stream >> extra) std::cout << "Extra character afters number\n";
        else
        {
            if (!(0 <= number && number < capacity))
                std::cout << "Invalid Index!" << number << std::endl;
            else
            {
                valid = true;
                contacts[number].show();
            }
        }
    }while(valid == false);
    
}