#pragma once
#include <thread>
#include "Game.h";
#include "Wall.h"
#include "Player.h"
#include "Exit.h"
Game::Game() {
	LoadContent();
	Init();
}
Game::~Game() {
    _Updatables->clear();
    _Drawables->clear();
    delete _DrawMatrix;
}
void Game::Draw() {
    _DrawMatrix->ClearMatrix();
    for (auto obj : *_Drawables)
        obj->Draw(_DrawMatrix);
    _DrawMatrix->Draw();
}
void Game::Update(char key) {
    for (auto obj : *_Updatables)
        obj->Update(key);
}
void Game::LoadContent() {

}
void Game::Init() {
	p_Ended = false;
    _Updatables = new vector<IUpdatable*>();
    _Drawables = new vector<IDrawable*>();
    _DrawMatrix = new DrawMatrix(Vector2Int(100, 18), ' ');
    CreateEntities();
}
void Game::CreateEntities() {
    for (int i = 0; i < 150; i++)
    {
        auto obj = new Wall(Vector2Int(rand() % 100, -rand() % 18));
        _Drawables->push_back(obj);
        _Updatables->push_back(obj);
    }
    auto player = new Player(Vector2Int(rand() % 50, -rand() % 9), _DrawMatrix, &p_Ended);
    _Drawables->push_back(player);
    _Updatables->push_back(player);
    auto obj = new Exit(Vector2Int(rand() % 50 + 49, -(rand() % 9 + 8)));
    _Drawables->push_back(obj);
    _Updatables->push_back(obj);
}
void Game::Start() {
    StartCycle();
}
void Game::StartCycle() {
    while (!p_Ended)
    {
        if (system("CLS")) system("clear");
        Draw();
        ReadEvents();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    End();
}
void Game::End() {
    if (system("CLS")) system("clear");
    cout << "Good Game";
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