#include "Vector2Int.h"
#include <math.h>
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
Vector2Int Vector2Int::operator-(Vector2Int& vec) {
    return Vector2Int(X - vec.X, Y - vec.Y);
}
Vector2Int Vector2Int::operator+(Vector2Int& vec) {
    return Vector2Int(X + vec.X, Y + vec.Y);
}
Vector2Int Vector2Int::ToDirection() {
    return Vector2Int(X != 0 ? X/abs(X) : 0, Y !=0 ? Y/abs(Y) : 0);
}