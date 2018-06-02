#pragma once
#include "Pane.h"
#include <iostream>

using namespace std;

class InputPane :
    public Pane
{
public:
    InputPane(int x, int y, int width, int height);
    ~InputPane();

    virtual void Draw();
};