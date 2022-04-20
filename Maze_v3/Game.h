#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include "IDrawable.h"
#include "IUpdatable.h"
#include "DrawMatrix.h"
using namespace std;
class Game {
public:
	void Start();
	Game();
	~Game();
private:
	bool p_Ended;
	vector<IUpdatable*>* _Updatables;
	vector<IDrawable*>* _Drawables;
	DrawMatrix* _DrawMatrix;
	void LoadContent();
	void Init();
	void CreateEntities();
	void Update(char key);
	void Draw();
	void StartCycle();
	void End();
	void ReadEvents();
	void ReadKey(KEY_EVENT_RECORD);
};