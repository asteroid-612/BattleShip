#pragma once
#include "Ship.h"

class Cruiser :
    public Ship
{
public:
    Cruiser();
    ~Cruiser();
};

Cruiser::Cruiser() : Ship(3)
{
    m_Type = CRUISER;
}

Cruiser::~Cruiser()
{
    
}