#pragma once
#include <vector>
#include <iostream>

enum ShipType // 순서에 대해서 값을 정해주므로 추가 삭제 할때마다 값이 초기화된다. 
{
    DATA_ERROR = -1,
    DATA_NONE, // **** 그래서 0의 값에는 초기화 값을 넣어놓는다!! ****
    AIRCRAFT, // enum은 0에서 시작한다. 사실상 내부에서는int이다.
    BATTLESHIP, // 1
    CRUISER, // 2
    DESTROYER, // 3...
};

static const int MAP_SIZE = 8;

// 클래스보다 간단하게, return을 두개 하고싶다. 
struct Position{
    Position() : x(0),y(0) {}
    // 구조체 초기화도 이런식으로 해주면 된다. class와 비슷하게 굴러감.
    int x;
    int y;
    Position(int m_x, int m_y) : x(m_x), y(m_y){}
    // 방향과 위치는 같은 구조체를 사용한다. 
    // 연산자 오버로딩은 상식적으로 접근할것. 
    Position operator +(const Position& pos) const // 자기 자신(멤버변수)의 값을 안바꾸고, 받은 값도 값을 안바꾼다.
    // Position& operator 안에서 만든 Position이지만 return 하자마자 
    {
        Position retPos;
        retPos.x = x + pos.x;
        retPos.y = y + pos.y;
        return retPos;
    }

    Position operator -(const Position& pos) const // 자기 자신(멤버변수)의 값을 안바꾸고, 받은 값도 값을 안바꾼다.
    // Position& operator 안에서 만든 Position이지만 return 하자마자 
    {
        Position retPos;
        retPos.x = x - pos.x;
        retPos.y = y - pos.y;
        return retPos;
    }
    // 뭐이거는 몰라도 됨. 
    /*
    Position operator *(const Position pos) // 얘는 뭘 의미하는 것일까? 
    // 인자를 float로 바꿔주고, Position retPos... 해서 걔를 곱해서 return 해준다.
    */
    friend std::ostream& operator <<(std::ostream& os, Position pos) // 얘는 뭘 받아야하지? 그걸 정의할 수가 없다. ㅠㅠ 
    {
    os << "x: "<< pos.x << " ";
    os << "y: "<< pos.y;
    return os; // 타겟과의 관계가 아니라 ostream과 나의 관계만 정의한다. ( 나 = Position .)
    // operator <<는 어떤 특정한 클래스나 구조체의 내부함수로 만들지 않는다. 
    // 외부 함수로 바꿔도 괜찮다. 그러나 그렇게 하면 Pos를 두개를 넣어줘야 할 것이다. 
    }
};
// 내부함수를 외부에 선언하는것은 friend라는 keyword를 사용해서 가능하게 한다. 
// 얘가 반환하는건 꼭 ostream이어야 한다.  이렇게 밖으로 하면 중복선언이 되므로 static에 해주거나 내부에 넣는게 더 좋다.
// friend 
// ostream은 항상 참조로 해줘야한다.


enum HitResult 
{
    MISS,
    HIT,
    DESTROY,
};

