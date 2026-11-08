#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    hitPoints = 10;
    enegryPoints = 10;
    attackDamage = 0;
    std::cout << "Constructor is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "Copy is called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->hitPoints = other.hitPoints;
        this->attackDamage = other.attackDamage;
        this->enegryPoints = other.enegryPoints;
        this->_name = other._name;
    }
    std::cout << "Copy assignment is called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor is called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (enegryPoints == 0 || hitPoints == 0)
    {
        std::cout << "No Energy or No HealthPoint" << std::endl;
        return;
    }
    enegryPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " << attackDamage << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= hitPoints )
    {
        hitPoints = 0;
        std::cout << amount << " is more than health points! No survival!" << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << amount << " damage of points happend." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (enegryPoints == 0 || hitPoints == 0)
    {
        std::cout << "No Energy or No HealthPoint" << std::endl;
        return;
    }
    hitPoints += amount;
    enegryPoints--;
    std::cout << amount << " of points repaired." << std::endl;
}
