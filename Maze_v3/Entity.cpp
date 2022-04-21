#include "Entity.h"
Entity::Entity(Vector2Int position, char symbolToDraw) {
	p_Position = position;
	p_SymbolToDraw = symbolToDraw;
}
void Entity::Draw(Field* field) {
	field->ChangePointThrowGlobalPosition(p_SymbolToDraw, p_Position);
}
Vector2Int Entity::GetCopyOfPosition() {
	return p_Position;
}