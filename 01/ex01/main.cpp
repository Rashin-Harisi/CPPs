/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:23:32 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/14 14:23:33 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main(void)
{
    int N = 0;
    Zombie *zombies = zombieHorde(N, "Zombie");
    if (zombies == NULL)
    {
        return (1);
    }
    for (int i = 0; i < N; i++)
    {
        zombies[i].announce();
    }
    delete[] zombies;
    return (0);
}