#include "Player.h"
Player::Player(Vector2Int position, DrawMatrix* matrix) {
	p_Position = position;
	p_Matrix = matrix;
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
	step += p_Position;
	if (p_Matrix->GetDot(step) == '#')
		return;
	p_Position = step;
}
void Player::Draw(DrawMatrix* drawMatrix) {
	drawMatrix->Change('@', p_Position);
}