#pragma once

#include "IRenderer.h"
namespace sf 
{
	class RenderWindow; 
 }

class SFMLRenderer : public IRenderer
{
	public:
		SFMLRenderer(const Vector2D& bounds, float scale = 1 );
		~SFMLRenderer() override;

		void Update(PlayField& world) override;

		void Draw() override;

		float GetScale() const;
		void SetScale(float scale);
		
	private:
		float m_scale;
		sf::RenderWindow* m_window;
};