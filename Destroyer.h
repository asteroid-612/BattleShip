#pragma once
#include "Ship.h"

class Destroyer:
    public Ship
{
public:
    Destroyer();
    ~Destroyer();
};

Destroyer::Destroyer() : Ship(2)
{
    m_Type = DESTROYER;
}

Destroyer::~Destroyer()
{
    
}