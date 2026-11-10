#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Constructor from WrongAnimal class is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
    std::cout << "Copy from WrongAnimal class is called" << std::endl;

}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "Copy operator from WrongAnimal class is called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor from WrongAnimal class is called" << std::endl;
}

const std::string WrongAnimal::getType() const
{
    return (type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "General Sound of WrongAnimal" << std::endl;
}