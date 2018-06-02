#pragma once
#include "CommonDefine.h"
// 거의 공통된 데이터 타입이 되고, 헷갈리게 된다. 
// enum은 명시적으로 써준 값을 하나씩 증가시켜서 한다. 
// enum ShipType을 만들어줌. _> map.h에서 끌어와서 쓰면 
// 어쨌든 서로 커플링이 계속됨 ㅠㅠ enum떄문에. > file끼리의 coupling이 많으면
// 컴파일 시간이 늘ㅇㅓ남... 

class Ship
{
public:
    Ship(int length); // 얘는 무조건 length를 가져야함. 생성자함수에 인자로 length 를 받는다.
    virtual ~Ship();

    std::vector <Position> GetShipPos() { return m_Pos; }
    ShipType GetType() const{ return m_Type; }
    int GetLength() const { return m_length; }
    void SetPosition(int index,const Position& pos);
    HitResult GetAttacked(const Position& pos); // 그러면 공격당했을때 m_Pos에 있는 애를 하나 밖으로 빼준다 -> 얘가 hp대신을 함.
    // 맵을 보지 않고 배를 보는 것으로 바꾼다. 배가 맞았는지 안맞앗는지를 배에 좌표를 주고 
    // 맞춘 좌표가 배의 좌표와 일치하는지를 확인해서 어떤 디스트로이어가 맞았는지를 확인한다. 
    // 디스트로이어가 두대 존재하므로 두 디스트로이어중 어떤 디스트로이어가 맞았는지를 확인하기 위해서는 이렇게 해야한다. 
protected:
    HitResult m_Result;
    ShipType m_Type;
    int m_length;
    // 디폴트 hp는 length와 같다. 
    //Position* m_Pos; // 길이만큼 position을 가진다. (벡터를 이용해서 넣는다.) 
    std::vector <Position> m_Pos; // 길이를 여유있게 넣어놓는다. 그게 좋다. 할당해놓은것 뿐, 미리 값을 넣는건 아니다. CAPACITY로 넣어진 양을 볼 수 있음. 
};