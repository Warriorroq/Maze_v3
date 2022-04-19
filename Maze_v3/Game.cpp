#pragma once
#include "Game.h";
Game::Game() {
	LoadContent();
	Init();
}
Game::~Game() {

}
void Game::Draw() {
    p_DrawMatrix->Draw();
}
void Game::Update() {

}
void Game::LoadContent() {

}
void Game::Init() {
	p_Ended = false;
    p_Updatables = new vector<IUpdatable>();
    p_Drawables = new vector<IDrawable>();
    p_DrawMatrix = new DrawMatrix(Vector2Int(90, 9), '#');
}
void Game::Start() {
	Draw();
	while (!p_Ended)
	{
		Update();
        ReadEvents();
        if (system("CLS")) system("clear");
        Draw();
        this_thread::sleep_for(chrono::milliseconds(500));
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
    cout << key.uChar.AsciiChar;
}