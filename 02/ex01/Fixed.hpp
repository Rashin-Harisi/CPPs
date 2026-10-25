#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed(const int n);
    Fixed(const float f);
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    int getRawBits()const;
    void setRawBits(int const raw);
    float toFloat()const;
    int toInt()const;
    ~Fixed();
private:
    static const int fracctionalBits = 8; //the number of fractional bits
    int value;
};

std::ostream &operator<<(std::ostream &out, const Fixed &c);
#endif // FIXED_HPP