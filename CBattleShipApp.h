#pragma once
#include "CommonDefine.h"
class CBattleShipMap;
class StatPane;
class InputPane;
class GameManager;
#include "Map.h"

class CBattleShipApp
{
    public:
        CBattleShipApp(); 
        ~CBattleShipApp();

        void Play();

    protected:
        void Init();
        void Render();
        void Destroy();

    protected:
        CBattleShipMap* m_pAttacker;
        CBattleShipMap* m_pDefender;// 어태커 디펜더 맵을 만들기 위해서 각 필드 생성.
        StatPane* m_pStatPane;
        InputPane* m_pinputPane;
        GameManager* m_GameManager;
        Map* defendermap;
};