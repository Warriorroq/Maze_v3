#pragma once
#include <ctime>
#include "Game.h";
int main()
{
	srand(time(0));
	Game::CreateGame();
	Game::StartGame();
	return 0;
}