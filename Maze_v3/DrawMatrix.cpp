#include "DrawMatrix.h"
DrawMatrix::DrawMatrix(Vector2Int size, char bg) 
{
	_bgSymbol = bg;
	_Size = Vector2Int(size.X, size.Y);
	auto total = size.X * size.Y;
	_DrawableMatrix = vector<char>(total);
	for (int i = 0; i < total; i++)
		_DrawableMatrix[i] = _bgSymbol;
}
DrawMatrix::~DrawMatrix() {
	_DrawableMatrix.clear();
}
void DrawMatrix::ClearMatrix() {
	auto total = _Size.X * _Size.Y;
	for (int i = 0; i < total; i++)
	{
		_DrawableMatrix[i] = _bgSymbol;
	}
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
	if (!PositionIsInMatrix(pos))
		return;
	_DrawableMatrix[pos.X + -pos.Y * _Size.X] = symbol;
}
char DrawMatrix::GetDot(Vector2Int pos) {
	if (!PositionIsInMatrix(pos))
		return ' ';
	return _DrawableMatrix[pos.X + -pos.Y * _Size.X];
}
bool DrawMatrix::PositionIsInMatrix(Vector2Int position) {
	if (position.Y > 0 || position.Y < -_Size.Y + 1)
		return false;
	if (position.X < 0 || position.X > _Size.X - 1)
		return false;
	return true;
}
