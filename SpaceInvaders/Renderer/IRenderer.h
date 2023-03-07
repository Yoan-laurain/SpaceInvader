#pragma once

#include "Utils/Vector2D.h"

class PlayField;

class IRenderer
{
	public:
		explicit IRenderer(const Vector2D& m_bounds);
		virtual ~IRenderer();

		virtual void Update(PlayField& world) = 0;
		virtual void Draw() = 0;

		const Vector2D& GetBounds() const;

		Vector2D m_bounds;
};