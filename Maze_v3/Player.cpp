#include "Player.h"
Player::Player(Vector2Int position, DrawMatrix* matrix, bool* end) {
	_Position = position;
	_Matrix = matrix;
	this->_End = end;
}
void Player::Update(char key) {
	Vector2Int step;
	switch (key) {
	case 'w':
		step = Vector2Int(0, 1);
		break;
	case 's':
		step = Vector2Int(0, -1);
		break;
	case 'a':
		step = Vector2Int(-1, 0);
		break;
	case 'd':
		step = Vector2Int(1,0);
		break;
	default:
		step = Vector2Int();
		break;
	}
	step += _Position;
	if (_Matrix->GetDot(step) == '#')
		return;
	if (_Matrix->GetDot(step) == 'E')
		*_End = true;
	_Position = step;
}
void Player::Draw(DrawMatrix* drawMatrix) {
	drawMatrix->Change('@', _Position);
}