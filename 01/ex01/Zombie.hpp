#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;

public:
    void announce(void);
    void setName(std::string str);
    Zombie();
    Zombie(std::string str);
    ~Zombie();
};

Zombie *zombieHorde(int N, std::string name);

#endif