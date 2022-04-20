#pragma once
#include "DrawMatrix.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Vector2Int.h"
class Player : public IDrawable, public IUpdatable {
public:
	Player(Vector2Int, DrawMatrix*, bool*);
	void Update(char) override;
	void Draw(DrawMatrix*) override;
private:
	Vector2Int p_Position;
	DrawMatrix* p_Matrix;
	bool* p_End;
};