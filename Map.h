#pragma once
#include "CommonDefine.h"

class Map
{
public:
    Map();
    ~Map();

    ShipType GetData(const Position& pos) const
    {
        if(pos.x<0 || pos.x >=MAP_SIZE || pos.y < 0 || pos.y >= MAP_SIZE)
            return DATA_ERROR;
        return m_Data[pos.x][pos.y];
    }

    void SetData(const Position& pos, ShipType type)
    {
        if(pos.x<0 || pos.x >=MAP_SIZE || pos.y < 0 || pos.y >= MAP_SIZE)
            return;
        m_Data[pos.x][pos.y] = type;
    }
    
protected: 
    // 우아하게 짜보자.. 
    ShipType m_Data[MAP_SIZE][MAP_SIZE]; 
    // **** 이렇게 하면 아무것도 없는 칸이 없다!! ****
    // **** 초기화 할 수 있는 값이 없다!! ****
    
    //%% 이렇게 define해서 사용하면 가능하다. %%
    //%% static const int MAP_SIZE = 8; 이렇게도 가능함. 꼭 static %%
    
    // a 가지고 aircraft라고 유추하는것은 인간이 하는 것이지, 
    // 좋은 코드는 아니다. a가 두개 들어오면 어떻게 할 예정? 
    
    // define으로 하는게 일반적인 값에 명시를 해줄 수 있다.
    // enum : define을 여러개 묶을때 사용하는것. 
};