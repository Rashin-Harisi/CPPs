/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:49:54 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/08 16:49:55 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap player1("John");
    ClapTrap player2("David");
    ClapTrap player3("Rashin");

    player1.attack("David");
    player1.takeDamage(20);
    player1.attack("David");


    player2.attack("John");
    player2.attack("A");
    player2.attack("B");
    player2.attack("C");
    player2.beRepaired(2);

    player3.attack("1");
    player3.attack("2");
    player3.attack("3");
    player3.attack("4");
    player3.attack("5");
    player3.attack("6");
    player3.attack("7");
    player3.attack("8");
    player3.attack("9");
    player3.attack("10");
    player3.attack("11");

    return 0;
}
