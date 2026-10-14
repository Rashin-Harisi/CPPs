/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:23:37 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/14 14:23:38 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string str)
{
    name = str;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed." << std::endl;
}

Zombie::Zombie(void)
{
}

void Zombie::setName(std::string str)
{
    name = str;
}