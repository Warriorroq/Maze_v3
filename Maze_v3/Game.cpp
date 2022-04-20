#pragma once
#include "Game.h";
#include "Wall.h"
Game::Game() {
	LoadContent();
	Init();
}
Game::~Game() {

}
void Game::Draw() {
    p_DrawMatrix->ClearMatrix();
    for (auto obj : *p_Drawables)
        obj->Draw(p_DrawMatrix);
    p_DrawMatrix->Draw();
}
void Game::Update() {
    for (auto obj : *p_Updatables)
        obj->Update();
}
void Game::LoadContent() {

}
void Game::Init() {
	p_Ended = false;
    p_Updatables = new vector<IUpdatable*>();
    p_Drawables = new vector<IDrawable*>();
    p_DrawMatrix = new DrawMatrix(Vector2Int(100, 9), ' ');
    for (int i = 0; i < 1000; i++)
    {
        auto obj = new Wall(Vector2Int(rand() % 200, -rand() % 9));
        p_Drawables->push_back(obj);
        p_Updatables->push_back(obj);
    }
}
void Game::Start() {
	while (!p_Ended)
	{
        ReadEvents();
        if (system("CLS")) system("clear");
        Draw();
        Update();
	}
}
void Game::ReadEvents() {
    DWORD cNumRead, fdwMode, i;
    INPUT_RECORD irInBuf[128];
    if (!ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),irInBuf,128,&cNumRead)) 
        ExitProcess(0);

    for (i = 0; i < cNumRead; i++)
    {
        if (irInBuf[i].EventType == KEY_EVENT)
            ReadKey(irInBuf[i].Event.KeyEvent);
    }
}
void Game::ReadKey(KEY_EVENT_RECORD key) {
    
}