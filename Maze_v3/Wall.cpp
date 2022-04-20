#include "Wall.h"
Wall::Wall(DrawMatrix* matrix, Vector2Int pos) {
	_DrawMatrix = matrix;
	Position = pos;
}
void Wall::Draw() {
	_DrawMatrix->Change('#', Position);
}
void Wall::Update() {
	
	Position.X--;
}