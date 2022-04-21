#include "Field.h"
Field::Field(Camera* camera, char bg) 
{
	_BackgroundSymbol = bg;
	_MainCamera = camera;
	auto total = camera->renderSize.X * camera->renderSize.Y;
	_DrawableField = vector<char>(total);
	for (int i = 0; i < total; i++)
		_DrawableField[i] = _BackgroundSymbol;
}
Field::~Field() {
	_DrawableField.clear();
}
void Field::ClearField() {
	auto total = _MainCamera->renderSize.X * _MainCamera->renderSize.Y;
	for (int i = 0; i < total; i++)
	{
		_DrawableField[i] = _BackgroundSymbol;
	}
}
void Field::Draw() {
	for(int i = 0; i < _MainCamera->renderSize.X + 1; i++)
		cout << ">";
	DrawField();
	cout <<'>' << '\n';
	for (int i = 0; i < _MainCamera->renderSize.X+2; i++)
		cout << ">";
	cout << '\n';
}
void Field::DrawField() {
	auto total = _MainCamera->renderSize.X * _MainCamera->renderSize.Y;
	for (int i = 0; i < total; i++)
	{
		if (i % _MainCamera->renderSize.X == 0)
			cout << ">\n>";
		cout << _DrawableField[i];
	}
}
void Field::ChangePoint(char symbol, Vector2Int pos) {
	pos -= _MainCamera->position;
	if (!PositionIsInMatrix(pos ))
		return;
	auto drawPosition = pos;
	_DrawableField[pos.X + -pos.Y * _MainCamera->renderSize.X] = symbol;
}
char Field::GetPoint(Vector2Int pos) {
	pos -= _MainCamera->position;
	if (!PositionIsInMatrix(pos))
		return ' ';
	return _DrawableField[pos.X + -pos.Y * _MainCamera->renderSize.X];
}
bool Field::PositionIsInMatrix(Vector2Int position) {
	if (position.Y > 0 || position.Y < -_MainCamera->renderSize.Y + 1)
		return false;
	if (position.X < 0 || position.X > _MainCamera->renderSize.X - 1)
		return false;
	return true;
}
