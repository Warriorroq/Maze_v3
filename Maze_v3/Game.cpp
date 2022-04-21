#pragma once
#include <thread>
#include "Game.h";
#include "Player.h"
Game::Game() {
    p_Ended = false;
    _Updatables = vector<IUpdatable*>();
    _Drawables = vector<IDrawable*>();
    CreateEntities();
}
Game::~Game() {
    _Updatables.clear();
    _Drawables.clear();
    delete _DrawMatrix;
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
    for (int i = 0; i < 400; i++)
        ConnectEntity(new Entity(Vector2Int(rand() % 100 + 49, -(rand() % 100 + 8)), '#'));
    ConnectEntity(new Player(Vector2Int(rand() % 50 + 100, -(rand() % 9 + 50)), _DrawMatrix, &p_Ended, mainCamera));
    ConnectEntity(new Entity(Vector2Int(rand() % 50 + 49, -(rand() % 9 + 8)),'E'));
}
void Game::ConnectEntity(Entity* entity) {
    _Drawables.push_back(entity);
    _Updatables.push_back(entity);
}
void Game::Start() {
    StartCycle();
}
void Game::StartCycle() {
    while (!p_Ended)
    {
        system("CLS clear");
        Draw();
        auto key = ReadKey();
        cout << key;
        Update(key);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    EndGame();
}
void Game::EndGame() {
    system("CLS clear");
    cout << "Good Game";
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