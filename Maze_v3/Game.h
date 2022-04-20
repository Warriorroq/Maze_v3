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
	vector<IUpdatable*>* p_Updatables;
	vector<IDrawable*>* p_Drawables;
	DrawMatrix* p_DrawMatrix;
	void LoadContent();
	void Init();
	void Update(char key);
	void Draw();
	void ReadEvents();
	void ReadKey(KEY_EVENT_RECORD);
};