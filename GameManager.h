#pragma once
class Player; // 클래스 전방선언.
class Map;
class Ship;

class GameManager
{
public:
    GameManager();
    ~GameManager();
    
    void Init(); // 뭐든 시작되면 
    void Play(); // 게임 하는거. 
    Map* Defendermap();
    // logic이 존재한다. 
    // 어태커가 공격하면 디펜더가 대답해줄수도 있고 
    // 게임 매니저가 대답을 해줄수도 있다. 
    // 어태커와 디펜더는 decoupling된 상태로 만들어줘야한다. 
    // 현재는 디펜더가 공격이 맞았는지 어쨌는지를 확인해주도록 만들어줄것, 
    // hit check 은 디펜더에서 일어나게 만들것이다. 

    
protected:
    Player* m_Attacker;
    Player* m_Defender;
};