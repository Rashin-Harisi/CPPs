#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
public:
    Point();
    Point(const float a , const float b);
    Point(const Point &other);
    Point &operator=(const Point &other);
    const Fixed &getX() const;
    const Fixed &getY() const;
    ~Point();

private:
    const Fixed x;
    const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif // POINT_HPP