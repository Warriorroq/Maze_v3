#pragma once
#include "Game.h";
#include "Vector2Int.h"
int main()
{
	auto game = new Game();
	game->Start();
	delete game;
	return 0;
}