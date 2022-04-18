#pragma once
#include "Game.h";
Game::~Game() {
	delete p_Scene;
}
void Game::Draw() {
	p_Scene->Draw();
}
void Game::Update() {
	p_Scene->Update();
}
void Game::LoadContent() {

}
void Game::Init() {
	p_Ended = false;
	p_Scene = new Scene("Start scene");
}
void Game::Start() {
	LoadContent();
	Init();
	Draw();
	while (!p_Ended)
	{
		Update();
		Draw();
	}
}