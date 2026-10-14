/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:24:09 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/14 14:24:10 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
private:
    std::string name;
    Weapon &weaponA;

public:
    void attack();
    HumanA(std::string str, Weapon &weapon);
    ~HumanA();
};

#endif