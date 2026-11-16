#include "Fixed.hpp"

Fixed::Fixed(const int n)
{
    int raw;
    if ((n > INT_MAX / (1 << fracctionalBits)) || 
        (n < INT_MIN / (1 << fracctionalBits)))
        throw std::overflow_error("Integer construction overflow!");
    raw = n * ( 1 << fracctionalBits); // 1 << 8 = 2^8= 256
    setRawBits(raw);
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    double raw;
    raw = static_cast<double>(f) * (1 <<fracctionalBits);
    if (! (raw >= static_cast<double>(INT_MIN) && 
        raw <= static_cast<double>(INT_MAX)))
        throw std::overflow_error("Float constructor overflow!");
    float rounded = roundf(static_cast<float>(raw));
    setRawBits(static_cast<int>(rounded));
}

Fixed::Fixed()
{
    value = 0;
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
     //std::cout << "Destructor called" << std::endl;
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

bool Fixed::operator >(const Fixed &other)const{return (value > other.value);}
bool Fixed::operator <(const Fixed &other)const{return (value < other.value);}
bool Fixed::operator >=(const Fixed &other)const{return (value >= other.value);}
bool Fixed::operator <=(const Fixed &other)const{return (value <= other.value);}
bool Fixed::operator ==(const Fixed &other)const{return (value == other.value);}
bool Fixed::operator !=(const Fixed &other)const{return (value != other.value);}

Fixed Fixed::operator + (const Fixed &other)const
{
    Fixed result;
    double raw = static_cast<double>(value) + other.value;
    if (INT_MIN > raw || raw > INT_MAX)
    {
        throw std::overflow_error("Additional result overflowed!");
    }
    result.setRawBits(static_cast<int>(raw));
    return (result);
}

Fixed Fixed::operator - (const Fixed &other)const
{
    Fixed result;
    double raw = static_cast<double>(value) - other.value;
    if (INT_MIN > raw || raw > INT_MAX)
    {
        throw std::overflow_error("Subtraction result overflowed!");
    }
    result.setRawBits(static_cast<int>(raw));
    return (result);
}

Fixed Fixed::operator * (const Fixed &other)const
{
    Fixed result;
    double raw = (static_cast<double>(value) * other.value) / (1 << fracctionalBits);
    if (raw >= 0)
        raw += 0.5f;
    else
        raw -= 0.5f;
    if (INT_MIN > raw || raw > INT_MAX)
    {
        throw std::overflow_error("Multiplication result overflowed!");
    }
    result.setRawBits(static_cast<int>(raw));
    return (result);
}

Fixed Fixed::operator / (const Fixed &other)const
{
    Fixed result;
    if (other.value == 0) throw std::domain_error("Division by zero");
    double raw = (static_cast<double>(value) * (1 << fracctionalBits)) / other.value;
    if (raw >= 0)
        raw += 0.5f;
    else
        raw -= 0.5f;
    if (INT_MIN > raw || raw > INT_MAX)
    {
        throw std::overflow_error("Division result overflowed!");
    }
    result.setRawBits(static_cast<int>(raw));
    return (result);
}

Fixed &Fixed::operator++()
{
    Fixed &ref = *this;
    if (ref.value == INT_MAX) throw std::overflow_error("Pre-increment result overflowed");
    ref.value += 1;
    return (ref);
    // value += 1;
    // return (*this);
}

Fixed Fixed::operator++(int)
{
    if (value == INT_MAX) throw std::overflow_error("Post-increment result overflowed");
    Fixed prev(*this); //using copy constructor
    value += 1; // 1 raw value refers to 1/256 real value
    return (prev);
}

Fixed &Fixed::operator--()
{
    Fixed &ref = *this;
    if (ref.value == INT_MIN) throw std::overflow_error("Pre-decrement result overflowed");
    ref.value -= 1;
    return (ref);
    // value -= 1;
    // return (*this);
}

Fixed Fixed::operator--(int)
{
    if (value == INT_MIN) throw std::overflow_error("Post-decrement result overflowed");
    Fixed prev(*this); //using copy constructor
    value -= 1; // 1 raw value refers to 1/256 real value
    return (prev);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}