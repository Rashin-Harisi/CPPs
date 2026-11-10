/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:46:17 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/10 16:46:18 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Constructor from Dog is called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    *this = other ;
    std::cout << "Copy from Dog is called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << "Copy operator from Dog is called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Destructor from Dog is called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "WUFF WUFF" << std::endl;
}