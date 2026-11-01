#include "Point.hpp"

Point::Point() : x(0), y(0)
{
    // it can be done without initialization list
    //because Fixed constructor created them with 0 value
}

Point::Point(const float a , const float b): x(a) , y(b)
{
    // Fixed(float) constructor used inside the initialized list
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

Point &Point::operator=(const Point &other)
{
    (void) other;
    return *this;
}

Point::~Point()
{
}

const Fixed &Point::getX() const
{
    return (x);
}

const Fixed &Point::getY() const
{
    return (y);
}

