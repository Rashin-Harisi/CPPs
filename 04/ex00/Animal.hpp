#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "string"


class Animal
{
public:
    Animal();
    Animal(std::string name);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();
    virtual void makeSound() const;
    const std::string getType() const;

protected:
    std::string type;
    
};

#endif // ANIMAL_HPP