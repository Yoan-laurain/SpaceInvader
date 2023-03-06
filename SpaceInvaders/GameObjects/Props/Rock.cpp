#include "Rock.h"
#include "../SpaceInvaders/Renderer/ConsoleRenderer.h"
#include <string>

Rock::Rock()
{
	m_objType = new char[64];
	strcpy(m_objType, "Rock"); 
	m_sprite = RS_Rock;

	if (!m_texture.loadFromFile("Ressources/Asteroid.png"))
	{
		throw std::invalid_argument("Could not load texture");
	}

	m_sfmlSprite.setTexture(m_texture);
}

Rock::~Rock()
{
	delete[] m_objType;
}