#include "Wall.h"
Wall::Wall(Vector2Int pos) {
	_Position = pos;
}
void Wall::Draw(DrawMatrix* drawMatrix) {
	drawMatrix->Change('#', _Position);
}