#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Field.h"
#include "Entity.h"
using namespace std;
class Game {
public:
	void Start();
	Game();
	~Game();
private:
	bool p_Ended;
	vector<IUpdatable*> _Updatables;
	vector<IDrawable*> _Drawables;
	Field* _DrawMatrix;
	void CreateEntities();
	void Update(char key);
	void Draw();
	void StartCycle();
	void EndGame();
	char ReadKey();
	void ConnectEntity(Entity*);
};