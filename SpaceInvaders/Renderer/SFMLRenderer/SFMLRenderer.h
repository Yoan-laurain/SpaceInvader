#pragma once

#include "Renderer/IRenderer.h"
namespace sf 
{
	class RenderWindow; 
 }

class SFMLRenderer final : public IRenderer
{
	public:
		explicit SFMLRenderer(const Vector2D& bounds, float scale = 1 );
		~SFMLRenderer() override;

		void Update(PlayField& world) override;

		void Draw() override;

		float GetScale() const;
		void SetScale(float scale);

		sf::RenderWindow& GetWindow() const;
		
	private:
		float m_scale;
		sf::RenderWindow* m_window;
};