/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:46:17 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/10 17:33:17 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
    std::cout << "Constructor from Dog is called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Copy from Dog is called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Copy operator from Dog is called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Destructor from Dog is called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "WUFF WUFF" << std::endl;
}

void Dog::setIdea(int i, std::string idea)
{
    brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const
{
    return (brain->getIdea(i));
}