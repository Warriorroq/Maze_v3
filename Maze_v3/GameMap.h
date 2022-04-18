#pragma once
#include <list>;
#include "GameMapCell.h";
#include "GameObject.h";
using namespace std;
class GameMap : public GameObject{
public:
	enum MapTypeDraw { mini, room };
	list<list<GameMapCell>> *cells;
	GameMap();
	~GameMap();
	void Draw() override;
	string* ToString() override;
	MapTypeDraw type;
};