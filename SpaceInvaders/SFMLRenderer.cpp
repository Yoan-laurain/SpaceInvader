#include "SFMLRenderer.h"
#include "PlayField.h"
#include <SFML/Graphics/RenderWindow.hpp>

SFMLRenderer::SFMLRenderer(const Vector2D& bounds, float scale) :
	IRenderer(bounds),
	m_scale(scale),
	m_window(new sf::RenderWindow(sf::VideoMode(bounds.x * m_scale,bounds.y * m_scale),"Space Invaders"))
{
	m_window->setFramerateLimit(60);
}

SFMLRenderer::~SFMLRenderer()
{
	delete m_window;
}

void SFMLRenderer::Update(PlayField& world)
{
}

void SFMLRenderer::Draw()
{
	m_window->clear();

	for (auto& obj : GetGame()->GameObjects())
	{
		obj->m_sfmlSprite.setPosition(obj->m_pos.x * m_scale, obj->m_pos.y * m_scale);

		const sf::Vector2u& size = obj->m_sfmlSprite.getTexture()->getSize();
		obj->m_sfmlSprite.setScale(m_scale / size.x, m_scale / size.y);

		m_window->draw(obj->m_sfmlSprite); 
	} 
	
	m_window->display();
}

float SFMLRenderer::GetScale() const
{
	return m_scale;
}

void SFMLRenderer::SetScale(float scale)
{
	m_scale = scale;

	m_window->setSize(sf::Vector2u(m_bounds.x * m_scale, m_bounds.y * m_scale));
}