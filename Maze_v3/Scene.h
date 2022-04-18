#pragma once
#include "GameObject.h";
#include <list>
#include <string>
using namespace std;
class Scene : public IDrawable, public IUpdatable
{
public:
	list<GameObject>* objects;
	string *name;
	Scene(string name);
	~Scene();
	void Draw() override;
	void Update() override;
};