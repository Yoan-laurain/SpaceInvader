#pragma once
struct Vector2D
{
	Vector2D() : x(0), y(0) {}
	Vector2D(const Vector2D& vector)
	{
		x = vector.x;
		y = vector.y;
	}
	Vector2D(float x, float y) : x(x), y(y) {}

	~Vector2D() = default;

	bool IntCmp(const Vector2D& vec) const { return int(x) == int(vec.x) && int(y) == int(vec.y); }

	float x;
	float y;
};