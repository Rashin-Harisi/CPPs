/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:24:05 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/14 14:24:07 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &weapon): name(str), weaponA(weapon){}

HumanA::~HumanA(){}

void HumanA::attack(){
    std::cout << name << " attacks with their " << weaponA.getType() << std::endl;
}