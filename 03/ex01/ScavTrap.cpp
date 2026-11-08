/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:50:24 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/08 16:50:25 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Constructor from ScavTrap is called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    *this = other;
   std::cout << "Copy from ScavTrap is called." << std::endl;

}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
       this->attackDamage = other.attackDamage;
       this->hitPoints = other.hitPoints;
       this->energyPoints = other.energyPoints;
       this->_name = other._name;
    }
    std::cout << "Copy assignment from ScavTrap is called." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor from ScavTrap is called." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (energyPoints == 0 || hitPoints == 0)
    {
        std::cout << "No Energy or No HealthPoint" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target << " , causing " << attackDamage << " points of damage !" << std::endl;
}