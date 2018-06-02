#pragma once
#include <iostream>
#include <stdlib.h>
#include <ncurses.h>

using namespace std;

class Pane
{
public:
    Pane(int x, int y, int width, int height);
    virtual ~Pane();

    virtual void Draw();

protected:
    int m_x, m_y;
    int m_width, m_height;
    WINDOW* m_pWindow;
};