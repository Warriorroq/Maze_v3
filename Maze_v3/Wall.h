#pragma once
#include "IUpdatable.h"
#include "DrawMatrix.h"
#include "IDrawable.h"
class Wall : public IDrawable, public IUpdatable {
public:
	Wall(Vector2Int);
	void Draw(DrawMatrix*) override;
	void Update() override;
private:
	Vector2Int Position;
};