/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:23:43 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/14 14:23:44 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;

public:
    void announce(void);
    void setName(std::string str);
    Zombie();
    Zombie(std::string str);
    ~Zombie();
};

Zombie *zombieHorde(int N, std::string name);

#endif