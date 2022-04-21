﻿#pragma once
#include <thread>
#include "Game.h";
#include "Player.h"
#include "Entity.h"
#include "Fog.h"
Game* Game::_Game = nullptr;
Game::Game() {
    _Ended = false;
    _Updatables = vector<IUpdatable*>();
    _Drawables = vector<IDrawable*>();
    CreateEntities();
}
Game::~Game() {
    _Updatables.clear();
    _Drawables.clear();
    delete _DrawMatrix;
}
void Game::CreateGame()
{
    _Game = new Game();
}
void Game::Draw() {
    _DrawMatrix->ClearField();
    for (auto obj : _Drawables)
        obj->Draw(_DrawMatrix);
    _DrawMatrix->Draw();
}
void Game::Update(char key) {
    for (auto obj : _Updatables)
        obj->Update(key);
}
void Game::CreateEntities() {
    auto mainCamera = new Camera(Vector2Int(100, 18), Vector2Int());
    _DrawMatrix = new Field(mainCamera, ' ');
    for (int i = 0; i < 2000; i++)
        ConnectEntityToGameCycle(new Entity(Vector2Int(rand() % 300 + 49, -(rand() % 300 + 8)), '!'));
    ConnectEntityToGameCycle(new Player(Vector2Int(rand() % 50 + 100, -(rand() % 9 + 30)), _DrawMatrix, mainCamera));
    ConnectEntityToGameCycle(new Entity(Vector2Int(rand() % 50 + 49, -(rand() % 9 + 8)),'E'));
    ConnectEntityToGameCycle(new Fog(10, '#'));
}
void Game::ConnectEntityToGameCycle(Entity* entity) {
    _Drawables.push_back(entity);
    _Updatables.push_back(entity);
}
void Game::StartGame() {
    _Game->StartCycle();
}
void Game::StartCycle() {
    while (!_Ended)
    {
        system("CLS clear");
        Draw();
        auto key = ReadKey();
        cout << key;
        Update(key);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    system("CLS clear");
    cout << "Good Game";
    delete _Game;
}
void Game::EndGame() {
    _Game->_Ended = true;
}
char Game::ReadKey() {
    DWORD cNumRead, fdwMode, i;
    INPUT_RECORD irInBuf[128];
    if (!ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),irInBuf,128,&cNumRead)) 
        ExitProcess(0);

    for (i = 0; i < cNumRead; i++)
    {
        if (irInBuf[i].EventType == KEY_EVENT)
            return irInBuf[i].Event.KeyEvent.uChar.AsciiChar;
    }
}