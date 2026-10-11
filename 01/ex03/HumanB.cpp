#include "HumanB.hpp"

HumanB::HumanB(std::string str){
    name = str; 
    weaponB = NULL;
}

HumanB::~HumanB(){}

void HumanB::attack(){
    if (weaponB)
        std::cout << name << " attacks with their " << weaponB->getType() << std::endl;
    else
        std::cout << "no weapon yet!" << std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
    weaponB = &weapon; 
}