#include "Field.h"
Field::Field(Camera* camera, char backgroundChar) 
{
	_BackgroundSymbol = backgroundChar;
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
	auto totalCells = _MainCamera->renderSize.X * _MainCamera->renderSize.Y;
	for (int i = 0; i < totalCells; i++)
	{
		_DrawableField[i] = _BackgroundSymbol;
	}
}
void Field::Draw() {
	for(int i = 0; i < _MainCamera->renderSize.X + 1; i++)
		cout << ">";
	DrawField();
	cout <<'>' << '\n';
	for (int i = 0; i < _MainCamera->renderSize.X + 2; i++)
		cout << ">";
	cout << '\n';
}
void Field::DrawField() {
	auto totalCells = _MainCamera->renderSize.X * _MainCamera->renderSize.Y;
	for (int i = 0; i < totalCells; i++)
	{
		if (i % _MainCamera->renderSize.X == 0)
			cout << ">\n>";
		cout << _DrawableField[i];
	}
}
void Field::ChangePoint(char symbol, Vector2Int position) {
	position -= _MainCamera->position;
	if (!PositionIsInField(position ))
		return;
	auto drawPosition = position;
	_DrawableField[ConvertVector2ToFieldCellIndex(position)] = symbol;
}
char Field::GetPoint(Vector2Int position) {
	position -= _MainCamera->position;
	if (!PositionIsInField(position))
		return ' ';
	return _DrawableField[ConvertVector2ToFieldCellIndex(position)];
}
bool Field::PositionIsInField(Vector2Int position) {
	if (position.Y > 0 || position.Y < -_MainCamera->renderSize.Y + 1)
		return false;
	if (position.X < 0 || position.X > _MainCamera->renderSize.X - 1)
		return false;
	return true;
}
int Field::ConvertVector2ToFieldCellIndex(Vector2Int position) {
	return position.X + -position.Y * _MainCamera->renderSize.X;
}
