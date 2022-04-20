#pragma once
#include "IUpdatable.h"
#include "DrawMatrix.h"
#include "IDrawable.h"
class Exit : public IDrawable, public IUpdatable {
public:
	Exit(Vector2Int);
	void Draw(DrawMatrix*) override;
private:
	Vector2Int Position;
};