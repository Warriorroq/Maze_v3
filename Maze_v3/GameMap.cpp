#include "GameMap.h";
GameMap::GameMap()
{
	cells = new list<list<GameMapCell>>();
}
GameMap::~GameMap() {
	delete cells;
}
void GameMap::Draw() {
	
}
string* GameMap::ToString() {
	return nullptr;
}