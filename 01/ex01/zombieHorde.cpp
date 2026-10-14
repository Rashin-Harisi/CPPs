/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:23:47 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/14 14:23:48 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
    {
        std::cout << "Invalid number of zombies." << std::endl;
        return (NULL);
    }
    Zombie *ptrArr = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        ptrArr[i].setName(name);
    }
    return (ptrArr);
}