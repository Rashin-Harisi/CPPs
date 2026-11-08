/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClpaTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:50:05 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/08 17:02:11 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
        std::cout << "Constructor from ClapTrap is called." << std::endl;

}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "Copy from ClapTrap is called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->hitPoints = other.hitPoints;
        this->attackDamage = other.attackDamage;
        this->energyPoints = other.energyPoints;
        this->_name = other._name;
    }
    std::cout << "Copy assignment from ClapTrap is called." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor from CalpTrap is called." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints == 0 || hitPoints == 0)
    {
        std::cout << "No Energy or No HealthPoint" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " << attackDamage << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= hitPoints)
    {
        hitPoints = 0;
        std::cout << amount << " is more than health points! No survival!" << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << amount << " damage of points happend." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints == 0 || hitPoints == 0)
    {
        std::cout << "No Energy or No HealthPoint" << std::endl;
        return;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << amount << " of points repaired." << std::endl;
}
