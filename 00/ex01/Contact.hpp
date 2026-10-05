#ifndef CONTACT_H
#define CONTACT_H


#include <string>
#include <iostream>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkSecret;
public:
    void setFirstName(std::string name);
    void setLastName(std::string name);
    void setNickName(std::string name);
    void setPhoneNumber(std::string number);
    void setDarkSecret(std::string text);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkSecret() const;
    void show();
};

#endif 