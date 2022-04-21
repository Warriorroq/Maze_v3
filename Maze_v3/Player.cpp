#include "Player.h"
#include "Game.h"
Player::Player(Vector2Int position, Field* matrix, Camera* mainCamera) : Entity(position,'@') {
	_Field = matrix;
	this->_MainCamera = mainCamera;
	auto CameraOffSet = Vector2Int(_MainCamera->renderSize.X / 2, -_MainCamera->renderSize.Y / 2);
	_MainCamera->position = p_Position - CameraOffSet;
}
void Player::Update(char key) {
	Vector2Int offset = GetOffSet(key);
	TryToMoveOrIteract(offset);
	offset += p_Position;
}
Vector2Int Player::GetOffSet(char key) {
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
void Player::TryToMoveOrIteract(Vector2Int offSet) {
	auto newPlayerPosition = offSet + p_Position;
	char item = _Field->GetPoint(newPlayerPosition);
	if (item == '#')
		return; //can't move
	Iteract(item);
	p_Position = newPlayerPosition;
	_MainCamera->position += offSet;
}
void Player::Iteract(char item) {
	if (item == 'E')
		Game::EndGame();
}