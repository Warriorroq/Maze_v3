#pragma once
#include <thread>
#include "Game.h";
#include "Wall.h"
#include "Player.h"
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
void Game::Update(char key) {
    for (auto obj : *p_Updatables)
        obj->Update(key);
}
void Game::LoadContent() {

}
void Game::Init() {
	p_Ended = false;
    p_Updatables = new vector<IUpdatable*>();
    p_Drawables = new vector<IDrawable*>();
    p_DrawMatrix = new DrawMatrix(Vector2Int(100, 18), ' ');
    for (int i = 0; i < 150; i++)
    {
        auto obj = new Wall(Vector2Int(rand() % 100, -rand() % 18));
        p_Drawables->push_back(obj);
        p_Updatables->push_back(obj);
    }
    auto player = new Player(Vector2Int(rand() % 100, -rand() % 9), p_DrawMatrix);
    p_Drawables->push_back(player);
    p_Updatables->push_back(player);
}
void Game::Start() {
	while (!p_Ended)
	{
        if (system("CLS")) system("clear");
        Draw();
        ReadEvents();
        this_thread::sleep_for(chrono::milliseconds(100));
	}
}
void Game::ReadEvents() {
    /*DWORD cNumRead, fdwMode, i;
    INPUT_RECORD irInBuf[128];
    if (!ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),irInBuf,128,&cNumRead)) 
        ExitProcess(0);

    for (i = 0; i < cNumRead; i++)
    {
        if (irInBuf[i].EventType == KEY_EVENT)
            ReadKey(irInBuf[i].Event.KeyEvent);
    }*/
    char key;
    cin >> key;
    Update(key);
}
void Game::ReadKey(KEY_EVENT_RECORD keyboardCommand) {
    auto key = keyboardCommand.uChar.AsciiChar;
    Update(key);
}