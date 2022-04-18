#pragma once
#include <list>;
#include "IDrawable.h";
#include "IUpdatable.h";
#include <string>;
using namespace std;
class GameObject : public IDrawable, public IUpdatable {
public:
	void Draw() override;
	void Update() override;
	virtual string* ToString();
};