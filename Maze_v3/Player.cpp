#include "Player.h"
Player::Player(Vector2Int position, DrawMatrix* matrix, bool* end) {
	_Position = position;
	_Matrix = matrix;
	this->_End = end;
}
void Player::Update(char key) {
	Vector2Int step = GetStep(key);
	Move(step);
	step += _Position;
}
Vector2Int Player::GetStep(char key) {
	switch (key) {
	case 'w':
		return Vector2Int(0, 1);
	case 's':
		return Vector2Int(0, -1);
	case 'a':
		return Vector2Int(-1, 0);
	case 'd':
		return Vector2Int(1, 0);
	default:
		return Vector2Int();
	}
}
void Player::Move(Vector2Int step) {
	step += _Position;
	char item = _Matrix->GetDot(step);
	if (item == '#')
		return;
	Iteract(item);
	_Position = step;
}
void Player::Iteract(char item) {
	if (item == 'E')
		*_End = true;
}
void Player::Draw(DrawMatrix* drawMatrix) {
	drawMatrix->Change('@', _Position);
}