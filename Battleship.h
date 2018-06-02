#pragma once
#include "Ship.h"

class Battleship :
    public Ship
{
public:
    Battleship();
    ~Battleship();
};

Battleship::Battleship() : Ship(4)
{
    m_Type = BATTLESHIP;
}

Battleship::~Battleship()
{
    
}