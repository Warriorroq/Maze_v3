#pragma once
#include "IUpdatable.h"
#include "DrawMatrix.h"
class Wall : public IDrawable, public IUpdatable {
public:
	Wall(DrawMatrix*, Vector2Int);
	void Draw() override;
	void Update() override;
private:
	Vector2Int Position;
	DrawMatrix* _DrawMatrix;
};