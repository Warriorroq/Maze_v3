#pragma once
#include "Entity.h"
class Fog : public Entity {
public:
	Fog(int, char);
	void Draw(Field*) override;
private:
	int _ViewRadius;
};