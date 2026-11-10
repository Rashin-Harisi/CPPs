#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "Constructor from WrongCat class is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) :WrongAnimal(other)
{
    *this = other;
    std::cout << "Copy from WrongCat class is called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    std::cout << "Copy opperator from WrongCat class is called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor from WrongCat class is called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat MEWWWWW" << std::endl;
}

