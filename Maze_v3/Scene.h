#pragma once
#include "GameObject.h";
#include <list>;
#include <string>;
using namespace std;
class Scene : public IDrawable, public IUpdatable
{
public:
	Scene(string name, bool *endGame);
	~Scene();
	void Draw() override;
	void Update() override;
protected:
	list<GameObject>* p_Objects;
	string* p_Name;
	bool* p_EndGame;
};