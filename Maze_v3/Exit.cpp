#include "Exit.h"
Exit::Exit(Vector2Int pos) {
	Position = pos;
}
void Exit::Draw(DrawMatrix* drawMatrix) {
	drawMatrix->Change('E', Position);
}