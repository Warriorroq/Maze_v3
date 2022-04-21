#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Vector2Int.h"
#include "Camera.h"
using namespace std;
class Field {
public:
	Field(Camera*, char);
	~Field();
	Camera* mainCamera;
	void ChangePointThrowGlobalPosition(char, Vector2Int);
	void ChangePoint(char, Vector2Int);
	void Draw();
	void ClearField();
	char GetPoint(Vector2Int);
private:
	int ConvertVector2ToFieldCellIndex(Vector2Int);
	void DrawField();
	bool PositionIsInField(Vector2Int);
	char _BackgroundSymbol;
	vector<char> _DrawableField;
};