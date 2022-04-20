#include "Exit.h"
Exit::Exit(Vector2Int pos) {
	_Position = pos;
}
void Exit::Draw(DrawMatrix* drawMatrix) {
	drawMatrix->Change('E', _Position);
}