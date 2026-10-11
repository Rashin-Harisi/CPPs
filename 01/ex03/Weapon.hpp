#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>


class Weapon
{
private:
    std::string type;

public:
    const std::string &getType()const;
    void setType(std::string str);
    Weapon(std::string str);
    ~Weapon();
};

#endif