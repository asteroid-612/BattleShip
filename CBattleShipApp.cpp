#include <iostream>
#include <ncurses.h>
#include "CBattleShipApp.h"
#include "CBattleShipMap.h"
#include "StatPane.h"
#include "InputPane.h"

using namespace std;

CBattleShipApp::CBattleShipApp()
{

}

CBattleShipApp::~CBattleShipApp()
{
    
}
void CBattleShipApp::Init()
{
    initscr();
    start_color();
    cbreak();
    refresh();

    //컬러세팅
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    m_pAttacker = new CBattleShipMap(4, 16, MAP_SIZE + 3, MAP_SIZE + 2);
    m_pDefender = new CBattleShipMap(4, 4, MAP_SIZE + 3, MAP_SIZE + 2);
    m_pStatPane = new StatPane(30, 3, 30, 6);
    m_pinputPane = new InputPane(30, 15, 30, 4);

}

void CBattleShipApp::Play()
{
    Init();
    Render();
    Destroy();
}

void CBattleShipApp::Render()
{
    mvprintw(1, 1, "<< Battle Ship Game >>");

    m_pAttacker->Draw();
    m_pDefender->Draw();
    m_pStatPane->Draw();
    m_pinputPane->Draw();

    refresh();
}

void CBattleShipApp::Destroy()
{
    getch();
    endwin();
    delete m_pAttacker;
    delete m_pDefender;
}