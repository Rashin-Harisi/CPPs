/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:24:15 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/14 14:24:16 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *weaponB;

public:
    void attack();
    void setWeapon(Weapon &weapon);
    HumanB(std::string str);
    ~HumanB();
};

#endif