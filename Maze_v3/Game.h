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
	static void EndGame();
	static void CreateGame();
	static void StartGame();
private:
	Game();
	~Game();
	static Game* _Game;
	bool _Ended;
	vector<IUpdatable*> _Updatables;
	vector<IDrawable*> _Drawables;
	Field* _DrawMatrix;
	void CreateEntities();
	void Update(char key);
	void Draw();
	void StartCycle();
	char ReadKey();
	void ConnectEntityToGameCycle(Entity*);
};