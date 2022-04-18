#pragma once
#include "Game.h";
int main()
{
	auto game = new Game();
	game->Start();
	delete game;
	return 0;
}