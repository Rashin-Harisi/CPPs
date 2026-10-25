#include "Fixed.hpp"

Fixed::Fixed(const int n)
{
    int raw;
    raw = n * ( 1 << fracctionalBits); // 1 << 8 = 2^8= 256
    setRawBits(raw);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    int raw;
    if (f >= 0)
        raw = f * (1 << fracctionalBits) + 0.5f;
    else
        raw = f * (1 << fracctionalBits) - 0.5f;
    setRawBits(raw);
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
     std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits()const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat()const
{
    int raw;
    raw = getRawBits();
    return (static_cast<float>(raw) / (1 << fracctionalBits));
}

int Fixed::toInt()const
{
    int raw;
    raw = getRawBits();
    return (raw / (1 << fracctionalBits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
    out << c.toFloat();
    return out;
}