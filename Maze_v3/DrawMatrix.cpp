#include "DrawMatrix.h"
DrawMatrix::DrawMatrix(Vector2Int size, char bg) 
{
	_bgSymbol = bg;
	_Size = Vector2Int(size.X, size.Y);
	auto total = size.X * size.Y;
	_DrawableMatrix = vector<char>(total);
	for (int i = 0; i < total; i++)
	{
		_DrawableMatrix[i] = _bgSymbol;
	}
}
DrawMatrix::~DrawMatrix() {

}
void DrawMatrix::Draw() {
	auto total = _Size.X * _Size.Y;
	for (int i = 0; i < total; i++)
	{
		if (i % _Size.X == 0)
			cout << "\n";
		cout << _DrawableMatrix[i];
	}
}
void DrawMatrix::Change(char symbol, Vector2Int pos) {

}