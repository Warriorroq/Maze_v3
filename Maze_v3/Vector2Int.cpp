#include "Vector2Int.h"
Vector2Int::Vector2Int() {
    this->X = 0;
    this->Y = 0;
}
Vector2Int::Vector2Int(int X, int Y) {
	this->X = X;
	this->Y = Y;
}
Vector2Int& Vector2Int::operator+=(const Vector2Int& vec) {
    X += vec.X;
    Y += vec.Y;
    return *this;
}
Vector2Int& Vector2Int::operator-=(const Vector2Int& vec) {
    X -= vec.X;
    Y -= vec.Y;
    return *this;
}