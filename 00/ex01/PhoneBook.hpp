#ifndef PHONEBOOK_H
#define PHONEBOOK_H


#include "Contact.hpp"
#include <iostream>


class PhoneBook
{
private:
    Contact contacts[8];
    int capacity;
    int index;
public:
    PhoneBook(); //default constructor
    void add();
    void search();
    int getIndex();
};

#endif