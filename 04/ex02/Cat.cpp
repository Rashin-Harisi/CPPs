/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:46:14 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/10 18:30:32 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") , brain(new Brain())
{
    std::cout << "Constructor from Cat is called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    *this = other;
    std::cout << "Copy from Cat is called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << "Copy operator from Cat is called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Destructor from Cat is called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "MEWWWWWWWWW" << std::endl;
}
void Cat::setIdea(int i, std::string idea)
{
    brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const
{
    return (brain->getIdea(i));
}
