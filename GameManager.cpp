#include "GameManager.h"
#include "Player.h"
#include "Ship.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include <iostream>

using namespace std;

GameManager::GameManager()
{
    m_Attacker = NULL;
    m_Defender = NULL;
}

GameManager::~GameManager()
{
    if(m_Attacker)
    {
        delete m_Attacker;
        m_Attacker = NULL;
    }
    if(m_Defender)
    {
        delete m_Defender;
        m_Defender = NULL;
    }
}

void GameManager::Init()
{
    m_Attacker = new Player();
    m_Defender = new Player();

    // 여기가 다형성. ship 을 상속받은 abcd는 ship의 자리에 들어갈 수 있다. 
    std::vector<Ship*> vecShip;
    vecShip.push_back(new Aircraft());
    vecShip.push_back(new Battleship());
    vecShip.push_back(new Cruiser());
    vecShip.push_back(new Destroyer());
    vecShip.push_back(new Destroyer());
    // vector를 하나하나 돌면서 delete 해줘야하고, 그 이후에 clear가능.

    /*
    // 부모는 자식의 자리에 들어갈 수 없다. 
    vecShip[0]; // 의 타입은 무엇이지 ? Ship이다.
    vecShip[1]; // 얘도 물론 ship이다.
    Aircraft* pAircraft = (Aircraft*)vecShip[0]; // 할당된 메모리가 부모의 type으로 바뀌어서 들어와있는것  > 다형성.
    Battleship* pBS = (Battleship*)vecShip[1]; // 여기까지 된다.
    // 근데 잘못해서 형번환을 다른애들이랑 (숫자를 바꿔서) 해버려도 된다. 왜냐면 형번환은 졸라 강력해서 강제로 개통해버림.
    // 할땐 마음대로였겠지만 발을 뱰 수 없다.
    */


    // for문 안에 원래 auto pShip : vecShip 할 수 있음. 
    // for(unsigned int i=0; i<vecShip.size(); i++)
    // {
    //     // 만약 얘가 cruiser이면 출력 -> 포인터만 가지고는 판단할 수 없다.
    //     // 나중에 이것을 식별하기 위해서 식별자를 가지게 된다. 
    //     if(vecShip[i]->GetType() == CRUISER)
    //     {
    //         Cruiser* pCruiser = (Cruiser*)vecShip[i];
    //     }
    //     else if(vecShip[i]->GetType() == AIRCRAFT)
    //     {
    //         Aircraft* pAircraft = (Aircraft*)vecShip[i];
    //     }
    //     else if(vecShip[i]->GetType() == BATTLESHIP)
    //     {
    //         Battleship* pBattleship = (Battleship*)vecShip[i];
    //     }
    //     else if(vecShip[i]->GetType() == DESTROYER)
    //     {
    //         Destroyer* pDestroyer = (Destroyer*) vecShip[i];
    //     }
    // }
    m_Defender->SetupShips(vecShip);

}

void GameManager::Play()
{
    // 모든 배가 파괴될때까지 attacker에게 getAttackPos 하게 한다. 
    // 모든 배가 파괴되면 attacker가 공격을 중지한다. while True에서 break를 한다. 
    int Destroy_number = 0; // DESTROY 됐을때 얘를 증가시키는 방향으로, 
    while(Destroy_number < 5) {
        Position attack_to;
        attack_to = m_Attacker->GetAttackPos();
        HitResult defend_result;
        defend_result = m_Defender->HitCheck(attack_to);
        if(defend_result == 0){
            cout << "미스." << endl;
        }
        else if(defend_result == 1){
            cout << "배가 뭔가 맞았다." << endl;
        }        
        else{
            // 뭐가 맞았는지는 MAP에서 get data 해서 알 수 있음. 
            Destroy_number += 1;
            cout << "파괴되었습니다." << endl;
        }
    }
    cout << "게임이 끝났습니다." << endl;
}

Map* GameManager::Defendermap()
{
    return m_Defender->getMap();
}