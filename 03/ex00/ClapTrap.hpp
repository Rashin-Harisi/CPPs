#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

private:
    std::string _name;
    unsigned int hitPoints; //the Health of the ClapTrap
    unsigned int enegryPoints; 
    unsigned int attackDamage;
};

#endif // CLAPTRAP_HPP 