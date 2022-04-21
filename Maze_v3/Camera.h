#pragma once
#include "Vector2Int.h"
class Camera {
public:
	Camera(Vector2Int, Vector2Int);
	Vector2Int position;
	Vector2Int renderSize;
};