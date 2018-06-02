#pragma once
#include "Pane.h"
#include <vector>
#include "CommonDefine.h"
class Map;
//게임 화면 맵을 표시하는 클래스
class CBattleShipMap : Pane
{
public:
    CBattleShipMap(int x, int y, int width, int height); // 각각생성.
    CBattleShipMap(int x, int y, int width, int height, Map*& d_map);
    ~CBattleShipMap();
    void Draw();
protected:
    char m_mapData[MAP_SIZE][MAP_SIZE];
};