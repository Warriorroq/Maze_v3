#pragma once
#include "Field.h"
#include "Entity.h"
class Player : public Entity {
public:
	Player(Vector2Int, Field*, bool*, Camera*);
	void Update(char) override;
private:
	Camera* _MainCam;
	Vector2Int GetStep(char key);
	void Move(Vector2Int step);
	void Iteract(char item);
	Field* _Matrix;
	bool* _End;
};