#pragma once
#include <ctime>
#include "Game.h";
#include "Vector2Int.h"
int main()
{
	srand(time(0));
	auto game = new Game();
	game->Start();
	delete game;
	return 0;
}