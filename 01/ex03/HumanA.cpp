#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &weapon): name(str), weaponA(weapon){}

HumanA::~HumanA(){}

void HumanA::attack(){
    std::cout << name << " attacks with their " << weaponA.getType() << std::endl;
}