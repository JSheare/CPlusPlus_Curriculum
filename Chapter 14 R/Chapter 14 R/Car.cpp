#include "Car.h"
#include <iostream>

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
        c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_make != c2.m_make ||
        c1.m_model != c2.m_model);
}

bool operator<(const Car& car1, const Car& car2)
{
    if (car1.m_make != car2.m_make)
    {
        return (car1.m_make < car2.m_make);
    }
    else
    {
        return (car1.m_model < car2.m_model);
    }
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
    out << '(' << car.m_make << ", " << car.m_model << ')';

    return out;
}