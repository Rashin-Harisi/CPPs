/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 17:00:45 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/08 17:09:07 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Constructor from FragTrap is called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    *this = other;
   std::cout << "Copy from FragTrap is called." << std::endl;

}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
       this->attackDamage = other.attackDamage;
       this->hitPoints = other.hitPoints;
       this->energyPoints = other.energyPoints;
       this->_name = other._name;
    }
    std::cout << "Copy assignment from FragTrap is called." << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor from FragTrap is called." << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "High Fives Guys." << std::endl;
}
