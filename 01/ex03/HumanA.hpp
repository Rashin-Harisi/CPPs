#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
private:
    std::string name;
    Weapon &weaponA;

public:
    void attack();
    HumanA(std::string str, Weapon &weapon);
    ~HumanA();
};

#endif