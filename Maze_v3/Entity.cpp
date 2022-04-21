#include "Entity.h"
Entity::Entity(Vector2Int position, char symbolToDraw) {
	p_Position = position;
	p_SymbolToDraw = symbolToDraw;
}
void Entity::Draw(Field* field) {
	field->ChangePoint(p_SymbolToDraw, p_Position);
}