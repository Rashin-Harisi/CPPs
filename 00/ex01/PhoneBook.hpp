/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 09:31:42 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/12 09:31:48 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

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
