#include "Point.h"

#include <iostream>

Point Point::operator- () const
{
    return { -m_x, -m_y, -m_z };
}

Point Point::operator+ () const
{
    return { m_x, m_y, m_z };
}

// Return true if the point is set at the origin, false otherwise
bool Point::operator! () const
{
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

std::ostream& operator<<(std::ostream& out, const Point& point)
{
    out << '(' << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

    return out;
}