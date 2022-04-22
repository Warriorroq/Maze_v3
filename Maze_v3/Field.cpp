#include "Field.h"

Field::Field(Camera* camera, char backgroundChar) 
{
	_BackgroundSymbol = backgroundChar;
	mainCamera = camera;
	auto total = camera->renderSize.X * camera->renderSize.Y;
	_DrawableField = vector<char>(total);
	for (int i = 0; i < total; i++)
		_DrawableField[i] = _BackgroundSymbol;
}

Field::~Field() {
	_DrawableField.clear();
}

void Field::ClearField() {
	auto totalCells = mainCamera->renderSize.X * mainCamera->renderSize.Y;
	for (int i = 0; i < totalCells; i++)
		_DrawableField[i] = _BackgroundSymbol;
}

void Field::Draw() {
	for(int i = 0; i < mainCamera->renderSize.X + 1; i++)
		cout << ">";
	DrawField();
	cout <<'>' << '\n';
	for (int i = 0; i < mainCamera->renderSize.X + 2; i++)
		cout << ">";
	cout << '\n';
}

void Field::DrawField() {
	auto totalCells = mainCamera->renderSize.X * mainCamera->renderSize.Y;
	for (int i = 0; i < totalCells; i++)
	{
		if (i % mainCamera->renderSize.X == 0)
			cout << ">\n>";
		cout << _DrawableField[i];
	}
}

void Field::ChangePointThrowGlobalPosition(char symbol, Vector2Int position) {
	position -= mainCamera->position;
	ChangePoint(symbol, position);
}

void Field::ChangePoint(char symbol, Vector2Int position) {
	if (!PositionIsInField(position))
		return;
	_DrawableField[ConvertVector2ToFieldCellIndex(position)] = symbol;
}

char Field::GetPoint(Vector2Int position) {
	position -= mainCamera->position;
	if (!PositionIsInField(position))
		return ' ';
	return _DrawableField[ConvertVector2ToFieldCellIndex(position)];
}

bool Field::PositionIsInField(Vector2Int position) {
	if (position.Y > 0 || position.Y < -mainCamera->renderSize.Y + 1)
		return false;
	if (position.X < 0 || position.X > mainCamera->renderSize.X - 1)
		return false;
	return true;
}

int Field::ConvertVector2ToFieldCellIndex(Vector2Int position) {
	return position.X + -position.Y * mainCamera->renderSize.X;
}

char Field::GetBackGroundSymbol() {
	return _BackgroundSymbol;
}
