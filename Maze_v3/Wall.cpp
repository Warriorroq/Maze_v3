#include "Wall.h"
Wall::Wall(Vector2Int pos) {
	Position = pos;
}
void Wall::Draw(DrawMatrix* drawMatrix) {
	drawMatrix->Change('#', Position);
}
void Wall::Update() {

}