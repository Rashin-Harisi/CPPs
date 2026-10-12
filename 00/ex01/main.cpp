/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 09:30:11 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/12 09:30:15 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void menue(void)
{
	std::cout << "Welcome to the Phonebook! Please selec your desire request. \n";
	std::cout << "- ADD\n";
	std::cout << "- SEARCH\n";
	std::cout << "- EXIT\n";
}

int main(void)
{
	std::string input;
	PhoneBook phonebook;

	for (;;)
	{
		//std::cout << "index= " << phonebook.getIndex() << std::endl;
		menue();
		if (!std::getline(std::cin, input))
			break;
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break;
	}
}
