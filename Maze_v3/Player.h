#pragma once
#include "Field.h"
#include "Entity.h"
class Player : public Entity {
public:
	Player(Vector2Int, Field*, Camera*);
	void Update(char) override;
private:
	Camera* _MainCamera;
	Vector2Int GetOffSet(char key);
	void TryToMoveOrIteract(Vector2Int step);
	void Iteract(char item);
	Field* _Field;
};