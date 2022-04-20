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
	Vector2Int GetStep(char key);
	void Move(Vector2Int step);
	void Iteract(char item);
	Vector2Int _Position;
	DrawMatrix* _Matrix;
	bool* _End;
};