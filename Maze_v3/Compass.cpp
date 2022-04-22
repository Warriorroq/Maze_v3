#include "Compass.h"

Compass::Compass(Entity* player, Entity* exit, char compassArrow) : Entity(Vector2Int(), compassArrow) {
	_Player = player;
	_Exit = exit;
}

void Compass::Draw(Field* field) {
	Vector2Int directionVector = _Exit->GetCopyOfPosition();
	directionVector -= _Player->GetCopyOfPosition();
	directionVector = directionVector.ToDirection();
	auto renderSize = field->mainCamera->renderSize;
	for (int x = 0; x < 5; x++)
		for (int y = 0; y > -5; y--)
			field->ChangePoint(field->GetBackGroundSymbol(), Vector2Int(x + p_Position.X, y + p_Position.Y));
	auto compassCenter = Vector2Int(2, -2) + p_Position;
	for (int i = 0; i < 3; i++) {
		field->ChangePoint(p_SymbolToDraw, compassCenter);
		compassCenter += directionVector;
	}
}