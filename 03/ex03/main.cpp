/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 09:49:13 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/10 12:47:55 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


int main()
{
    std::cout << "\n--- 1. Names, attack, and special abilities ---\n";
    {
        DiamondTrap robot("John");

        // Expected: John and John_clap_name.
        robot.whoAmI();

        // Expected: ScavTrap's attack message with 30 damage.
        robot.attack("Target");

        // Both inherited abilities should be accessible.
        robot.guardGate();
        robot.highFivesGuys();
    }

    std::cout << "\n--- 2. Initial health and repair ---\n";
    {
        DiamondTrap robot("HealthTest");

        robot.takeDamage(99);      // 100 -> 1 HP
        robot.attack("Target");    // Expected: success, 30 damage
        robot.beRepaired(2);       // 1 -> 3 HP
        robot.takeDamage(2);       // 3 -> 1 HP
        robot.attack("Target");    // Expected: still succeeds
        robot.takeDamage(1);       // 1 -> 0 HP
        robot.attack("Target");    // Expected: refused
        robot.beRepaired(1);       // Expected: refused
    }

    std::cout << "\n--- 3. Exactly 50 energy points ---\n";
    {
        DiamondTrap robot("EnergyTest");

        for (int i = 0; i < 50; ++i)
            robot.attack("Target"); // All 50 should succeed.

        std::cout << "Next attack and repair should both be refused:\n";
        robot.attack("Target");     // 51st attack: refused
        robot.beRepaired(1);        // No energy left: refused
    }

    std::cout << "\n--- 4. Copy construction and copy assignment ---\n";
    {
        DiamondTrap source("David");
        source.takeDamage(99);     // Copy the current state: 1 HP.

        DiamondTrap copied(source);
        DiamondTrap assigned("John");
        assigned = source;

        // Both should print David and David_clap_name.
        copied.whoAmI();
        assigned.whoAmI();

        copied.takeDamage(1);      // Only copied should reach 0 HP.
        copied.attack("Target");   // Expected: refused
        assigned.attack("Target"); // Expected: succeeds, 30 damage
        source.attack("Target");   // Expected: succeeds, 30 damage

        assigned.takeDamage(1);
        assigned.attack("Target"); // Expected: refused
    }

    return 0;
}