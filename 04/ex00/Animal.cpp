#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Default Construction from Animal is called" << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
    std::cout << "Constructor from Animal is called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "Copy from Animal is called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "Copy operator from Animal is called" << std::endl;

    return *this;
}

Animal::~Animal()
{
    std::cout << "Destructor from Animal is called" << std::endl;

}

void Animal::makeSound() const
{
    std::cout << "General Sound of Animal" << std::endl;
}

const std::string Animal::getType() const
{
    return (type);
}