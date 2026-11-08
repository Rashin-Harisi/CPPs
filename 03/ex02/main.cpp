/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:57:50 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/08 17:12:43 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


int main()
{
    FragTrap player1("john");

    player1.attack("A");
    player1.attack("1");
    player1.attack("2");
    player1.attack("3");
    player1.attack("4");
    player1.attack("5");
    player1.attack("6");
    player1.attack("7");
    player1.attack("8");
    player1.attack("9");
    player1.attack("10");
    player1.beRepaired(5);
    player1.attack("11");

    

    return (0);
}