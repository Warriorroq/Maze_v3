#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "IDrawable.h"
#include "Vector2Int.h"
using namespace std;
class DrawMatrix : IDrawable {
public:
	DrawMatrix(Vector2Int, char);
	~DrawMatrix();
	void Change(char, Vector2Int);
	void Draw() override;
private:
	char _bgSymbol;
	Vector2Int _Size;
	vector<char> _DrawableMatrix;
};