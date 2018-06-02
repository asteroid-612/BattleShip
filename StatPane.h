#pragma once
#include "Pane.h"
#include <iostream>

using namespace std;
//스태터스를 표시하는 윈도우
class StatPane : Pane
{
public:
    StatPane(int x, int y, int width, int height);
    ~StatPane();

    virtual void Draw();
};