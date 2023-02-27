#include "Vector2D.h"

Vector2D::Vector2D() : x(0), y(0)
{
}

Vector2D::Vector2D(const Vector2D& vector)
{
	x = vector.x;
	y = vector.y;
}

Vector2D::Vector2D(float x, float y) : x(x), y(y)
{
}

bool Vector2D::IntCmp(const Vector2D& vec)
{
	return int(x) == int(vec.x) && int(y) == int(vec.y);
}
