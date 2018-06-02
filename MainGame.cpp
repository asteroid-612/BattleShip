#include "GameManager.h"
#include "CommonDefine.h"
#include <iostream>

int main()
{
    // Position pos;
    // pos.x = 10;
    // pos.y = 20;
    // pos = pos + pos; // 얘의 출력을 위해서는 연산자 오버로딩이 필요하다. 혹은 함수 정의가 필요하다. 
    // // iostream의 연산자를 오버로딩을 해야한다. 
    // std::cout << pos; // .. ostream을 output으로 

    GameManager manager;
    manager.Init();
    manager.Play();
    
    return 0;
}