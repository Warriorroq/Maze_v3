#pragma once
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Vector2Int.h"
class Entity : public IDrawable, public IUpdatable {
public:
	Entity(Vector2Int, char);
	void Draw(Field*) override;
protected:
	Vector2Int p_Position;
	char p_SymbolToDraw;
};