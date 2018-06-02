#pragma once
#include "CommonDefine.h"
class Map;
class Ship; // 클래스 전방선언.

// #define SHIPS std::vector<Ship>

class Player
{
public:
    Player();
    ~Player();
    // defender용.     
    // return값으로 true false하나로 되는게 아니다. 
    // destroy 되었는지 어쩃는지를 알려줘야하므로 enum을 사용한다. 
    // int값을 사용하지 않고 골져스 하게 만들어줬다!!!!!!! (허미!!!!!)
    Map* getMap() { return this->m_Map; }
    void SetupShips(const std::vector<Ship*>& ships);
    HitResult HitCheck(const Position& pos);
    // attacker용.
    Position GetAttackPos(); // 공격할 위치를 가져오는 함수.
    // x는 out x좌표, y는 out y좌표. 구별이 불가능하니까!
    // 좌표를 넣어야한다. 
    
    // 골져스하게 *********구조체를 사용한다***********

protected:
    Map* m_Map;
    std::vector<Ship*> m_ships;
};