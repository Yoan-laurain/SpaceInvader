#include "BetterAlien.h"
#include "../DirtySpaceInvaders/Renderer/ConsoleRenderer.h"

BetterAlien::BetterAlien() : Alien()
{
	m_health = 2.f;
	m_energy = 1.f;
	m_velocity = 0.5f;
	m_sprite = RS_BetterAlien;	

	if (!m_texture.loadFromFile("Ressources/BetterAlien.png"))
	{
		throw std::invalid_argument("Could not load texture");
	}

	m_sfmlSprite.setTexture(m_texture);

}

void BetterAlien::SetDirection(float iDirection)
{
	m_direction = iDirection; 
}

