/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:17:02 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/10 13:17:03 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    _name = name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
    std::cout << "Constructor from DiamondTrap is called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    *this = other;
    std::cout << "Copy from DiamondTrap is called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << "Copy operator from DiamondTrap is called." << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor from DiamondTrap is called." << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap Name is : " << _name << std::endl;
    std::cout << "ClapTrap Name is : " << ClapTrap::_name << std::endl;
}