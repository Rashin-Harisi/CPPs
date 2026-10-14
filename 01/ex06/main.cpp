/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:30:24 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/14 14:22:16 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char **argv)
{
    Harl harl;
    if (argc != 2) return (1);
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int index = -1;
    for (int i = 0; i < 4; i++)
    {
        if (argv[1] == levels[i])
        {
            index = i;
            break;
        }
    }
    switch(index)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
            std::cout << '\n';
            // fall through
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
            std::cout << '\n';
            // fall through
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
            std::cout << '\n';
            // fall through
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
            std::cout << '\n';
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return (0);
}