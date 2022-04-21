#include "Player.h"
Player::Player(Vector2Int position, Field* matrix, bool* end, Camera* mainCam) : Entity(position,'@') {
	_Matrix = matrix;
	this->_End = end;
	this->_MainCam = mainCam;
	auto nextPosition = Vector2Int(_MainCam->renderSize.X / 2, -_MainCam->renderSize.Y / 2);
	mainCam->position = p_Position - nextPosition;
}
void Player::Update(char key) {
	Vector2Int step = GetStep(key);
	Move(step);
	step += p_Position;
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
void Player::Move(Vector2Int offSet) {
	auto newPlayerPosition = offSet + p_Position;
	char item = _Matrix->GetPoint(newPlayerPosition);
	if (item == '#')
		return;
	Iteract(item);
	p_Position = newPlayerPosition;
	_MainCam->position += offSet;
}
void Player::Iteract(char item) {
	if (item == 'E')
		*_End = true;
}