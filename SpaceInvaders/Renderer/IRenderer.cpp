#include "IRenderer.h"

IRenderer::IRenderer(const Vector2D& m_bounds) : m_bounds(m_bounds) { }

IRenderer::~IRenderer() = default;

const Vector2D& IRenderer::GetBounds() const
{
    return m_bounds;
}
