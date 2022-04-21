#pragma once
#include "Entity.h"
class Compass : public Entity {
public:
	Compass(Entity*,Entity*,char);
	void Draw(Field*) override;
	Vector2Int offSet = Vector2Int();
private:
	Entity* _Player;
	Entity* _Exit;
};