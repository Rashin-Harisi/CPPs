#include "ICharacter.hpp"

ICharacter::ICharacter()
{
    // Initialize members
}

ICharacter::ICharacter(const ICharacter &other)
{
    // Copy members from other
}

ICharacter &ICharacter::operator=(const ICharacter &other)
{
    if (this != &other)
    {
        // Assign members from other
    }
    return *this;
}

ICharacter::~ICharacter()
{
}

