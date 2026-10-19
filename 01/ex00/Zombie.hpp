/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 09:49:01 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/19 09:49:02 by rabdolho         ###   ########.fr       */
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
    Zombie(std::string str);
    ~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif