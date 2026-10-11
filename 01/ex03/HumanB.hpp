#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *weaponB;

public:
    void attack();
    void setWeapon(Weapon &weapon);
    HumanB(std::string str);
    ~HumanB();
};

#endif