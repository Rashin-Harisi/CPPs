#include "Zombie.hpp"


int main(void)
{
    std::cout << "Usage outside the scope: " << std::endl;
    Zombie* newPtr = newZombie("Rashin");
    newPtr->announce();
    delete newPtr;
    std::cout << "Usage inside the scope: " << std::endl;
    randomChump("John");

    return (0);
}