/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:46:22 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/10 18:48:27 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Default Construction from Animal is called" << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
    std::cout << "Constructor from Animal is called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "Copy from Animal is called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "Copy operator from Animal is called" << std::endl;

    return *this;
}

Animal::~Animal()
{
    std::cout << "Destructor from Animal is called" << std::endl;

}

const std::string Animal::getType() const
{
    return (type);
}