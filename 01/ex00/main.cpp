/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:23:20 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/14 14:23:21 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main(void)
{
    std::cout << "Usage outside the scope: " << std::endl;
    Zombie* newPtr = newZombie("Rashin");
    newPtr->announce();
    delete newPtr;
    std::cout << "Usage inside the scope: " << std::endl;
    randomChump("John");

    return (0);
}