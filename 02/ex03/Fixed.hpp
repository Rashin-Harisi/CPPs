#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <climits>
#include <stdexcept>

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
    bool operator >(const Fixed &other)const;
    bool operator <(const Fixed &other)const;
    bool operator >=(const Fixed &other)const;
    bool operator <=(const Fixed &other)const;
    bool operator ==(const Fixed &other)const;
    bool operator !=(const Fixed &other)const;
    Fixed operator + (const Fixed &other)const;
    Fixed operator - (const Fixed &other)const;
    Fixed operator * (const Fixed &other)const;
    Fixed operator / (const Fixed &other)const;
    Fixed &operator++();    // ++a : prefix
    Fixed operator++(int);  // a++ : postfix
    Fixed &operator--();    // --a
    Fixed operator--(int);  // a--
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

private:
    static const int fracctionalBits = 8; //the number of fractional bits
    int value;
};

std::ostream &operator<<(std::ostream &out, const Fixed &c);
#endif // FIXED_HPP;