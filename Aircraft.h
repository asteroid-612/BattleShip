#pragma once
#include "Ship.h"

class Aircraft :
    public Ship
{
public:
    Aircraft();
    ~Aircraft();
};

Aircraft::Aircraft() : Ship(5)
{
    m_Type = AIRCRAFT;
}

Aircraft::~Aircraft()
{
    
}