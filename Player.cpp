#include "Player.h"
#include "Map.h" // cpp파일에서는 cpp파일만 수정하면 되므로 인클루드 부담 x
#include "Ship.h"
#include "CommonDefine.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Player::Player()
{
    m_Map = new Map();
    m_ships.resize(5);
}

Player::~Player()
{
    delete m_Map;

    for(unsigned int i=0; i<m_ships.size(); i++){
        if(m_ships[i])
        {
            delete m_ships[i];
        }
    }
    m_ships.clear();
}

void Player::SetupShips(const std::vector<Ship*>& ships)
{
    m_ships = ships; // m_Ship은 복사되면서 덮어쓴다 그래서 개수가 ships의 size로 바뀐다. 
    
    // 여기서부터 어려움. 배를 배치하는 것이 어렵다. 
    // logic이 어려우면 꼬인다. - 배를 가상으로 배치해보고 '가능하면' map을직접 건드린다. 
    // 진짜 map을 건드리면 다시 되돌리기가 어렵다. 
    // for 문은 원래 auto pShip : m_ships 로 써있었음.
    for(unsigned int i=0; i<m_ships.size(); i++)
    {
        // pShip은 m_ships[i]의 값을 가지는 포인터이다. 
        
        // 놓을 수 있는지 없는지를 확인해준다. Game manager가 확인해준다. 
        while(true)
        {
            Position pos; // 구조체 사용.
            pos.x = rand() % MAP_SIZE; // This is 깔 ㅡ 끔.
            pos.y = rand() % MAP_SIZE; 
            ShipType dataType = m_Map->GetData(pos);
            if(dataType != DATA_NONE) // 데이터논이 아니면 에러거나 뭐가있는거임.
                continue;
                
            //방향은 4방향. 
            Position dir; 
            if(rand() % 2){
                dir.x = rand() % 2 ? -1 : 1; // 0이나 1이 나옴, (-1,0)(1,0)
            }
            else{
                dir.y = rand() % 2 ? -1 : 1; // 0이나 1이 나옴, (0,-1)(0,1)
            }
            // 플래그를 만들어준다. 
            bool bSuccsess = true;
            // 얘는 가상의 map에 미리 배치해보는 for문이다. 
            for(int j=0; j< m_ships[i]->GetLength(); j++)
            {
                // 다음 포지션은
                // 이렇게 하면 증가하고 감소하고 할 수 있음. 
                // 연산자 오버라이딩
                pos = pos + dir;

                ShipType dataType = m_Map->GetData(pos);
                if(dataType != DATA_NONE) // 만약 값이 NONE이 아니라면 놓여있거나 맵 밖으로 튀어나갈것. 
                // 걸렸으면 while로 돌아가야하니까 break 해? > 노노. bool 값으로 간다. 
                {
                    bSuccsess = false;
                    break;
                }
                // DATA NONE 이다. 
                m_ships[i]->SetPosition(j, pos); // 이렇게 하면 배를 놓다가 되돌릴 수 없다.
                
            }
            if(bSuccsess)
            {
                // 배치가 잘 됐다! 
                // m_ships 가 가지고 있는 ship들이 성공한 pos값을 가지고 있음. 
                // UI에 m_ships의 pos에다가 각 ship의 이름의 대문자로 
                // 길이와 방향에 맞게 나열해준다.. 
                std::vector<Position> now_ship_pos = m_ships[i]->GetShipPos(); // 현재 배를 가져옴. 
                for(int k=0; k<m_ships[i]->GetLength(); k++)
                {
                    Position now_pos = now_ship_pos[k];
                    cout << now_pos << endl;
                    m_Map->SetData(now_pos, m_ships[i]->GetType());
                }
                break;
            }
            else
            {
                // 안타깝게도 배치가 잘 안되셨어요 고객님... 
                // while문으로 다시 돌아가서 처음부터 해야한다. 어떻게 해주면 되지? ,, 
                continue;
            }
        }                  
    }
    
}

HitResult Player::HitCheck(const Position& pos)
{
    // 배가 맞았는지 안 맞았는지를 확인한다. 
    // pos입력받은 값이 ship 의 m_Pos 에 존재하면 그값을 없앤다. 
    HitResult result;
    for(unsigned int i=0; i<m_ships.size(); i++)
    {
        // m_ships 에 있는 m_pos들의 값을 확인한다. pos와 같은 값이 있으면
        // 그 친구를 m_pos벡터에서 지워준다. 
        result = m_ships[i]->GetAttacked(pos); // 결과는 
        // 이 배가 맞았는지, 안맞았는지.
        if(result == 1)
        {
            result = HIT;
            break;
        }
        else if(result == 2)
        {
            result = DESTROY;
            break;
        }
        else
        {
            if(i == m_ships.size()-1) // 룹 돌았는데 HIT,DES안나옴
            {
                result = MISS;
                break;
            }
            else{
                continue;
            }
        }
    }
    return result;
}

Position Player::GetAttackPos()
{
    // UI에서 player에게 인풋을 받는 자리가 될것이다.    
    // 이 좌표를 가져다가 HItcheck를 한다. 
    // Play 동안은 끝나기 전가지 계속 hit check를 하고, 
    // Hit check의 destroy 값이 5번 나오면 끝난다. 
    Position attack_pos;
    cout << "x 입력 : ";
    cin >> attack_pos.x;
    cout << "y 입력 : ";
    cin >> attack_pos.y;

    return attack_pos;
}