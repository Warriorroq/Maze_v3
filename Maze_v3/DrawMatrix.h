#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Vector2Int.h"
using namespace std;
class DrawMatrix{
public:
	DrawMatrix(Vector2Int, char);
	~DrawMatrix();
	void Change(char, Vector2Int);
	void Draw();
	void ClearMatrix();
private:
	char _bgSymbol;
	Vector2Int _Size;
	vector<char> _DrawableMatrix;
};