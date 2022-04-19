#pragma once
struct Vector2Int {
public:
	Vector2Int();
    Vector2Int(int, int);
	int X;
	int Y;
	Vector2Int& operator+=(const Vector2Int&);
	Vector2Int& operator-=(const Vector2Int&);
};