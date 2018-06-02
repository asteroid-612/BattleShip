#include "Ship.h"

Ship::Ship(int length)
    :m_length(length)
{
    m_Pos.resize(length);
    m_Result = MISS;
}

Ship::~Ship()
{
}

void Ship::SetPosition(int index, const Position& pos)
{
    m_Pos[index] = pos;
}

HitResult Ship::GetAttacked(const Position& pos) // Miss, hit, destroy가 있음. 
{
    HitResult result = MISS;
    for(unsigned int i=0; i<m_Pos.size(); i++)
    {
        if(m_Pos[i].x == pos.x)
        {
            if(m_Pos[i].y == pos.y)
            {
                // vector m_Pos에서 pos와 일치하는 값이 
                // m_Pos[i]이므로, 이 값을 벡터에서 지운다. 그 다음 HIT을 return.
                m_Pos.erase(m_Pos.begin() + i);
                if(m_Pos.size() == 0){
                    result = DESTROY;
                    break;
                }
                else{
                    result = HIT;
                    break;
                }
            }
            else
            {
                result = MISS;
                break;
            }
        }
        else
        {
            result = MISS;
            break;
        }
    }
    
    return result;
}
