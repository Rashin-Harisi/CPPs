#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Constructor from Cat is called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    *this = other;
    std::cout << "Copy from Cat is called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << "Copy operator from Cat is called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Destructor from Cat is called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "MEWWWWWWWWW" << std::endl;
}
