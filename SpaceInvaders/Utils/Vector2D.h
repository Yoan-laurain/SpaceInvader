#pragma once
struct Vector2D
{
	Vector2D() : x(0), y(0) {}
	Vector2D(const Vector2D& vector)
	{
		x = vector.x;
		y = vector.y;
	}
	Vector2D(const float x, const float y) : x(x), y(y) {}

	~Vector2D() = default;

	bool IntCmp(const Vector2D& vec) const { return static_cast<int>(x) == static_cast<int>(vec.x) && static_cast<int>(y) == static_cast<int>(vec.y); }

	float x;
	float y;
};