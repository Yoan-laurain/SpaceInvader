#include "Alien.h"
#include "AlienLaser.h"
#include "Utils/GameRand.h"
#include "Renderer/ConsoleRenderer/ConsoleRenderer.h"
#include "PlayField.h"

Alien::Alien()
{
	m_objType = new char[64];
	strcpy(m_objType, "Alien");
	m_sprite = RS_Alien;

	if (!m_texture.loadFromFile("Ressources/Alien.png"))
	{
		throw std::invalid_argument("Could not load texture");
	}

	m_sfmlSprite.setTexture(m_texture);
}

Alien::~Alien()
{
	delete[] m_objType;
}

bool Alien::DecreaseHealth(const float damage)
{
	m_health -= damage; 
	return m_health <= 0;
}

void Alien::CheckBorderVertical()
{
	if ( m_pos.y >= GetGame()->m_bounds.y - m_velocity)
	{
		// kill player 
		GameObject* player = GetGame()->GetPlayerObject(); 

		if (player == nullptr)
		{
			throw std::invalid_argument("Player object is null");
		}

		if ( m_pos.y >= player->m_pos.y && m_pos.x >= player->m_pos.x || m_pos.y >= GetGame()->m_bounds.y)
		{
			GetGame()->RemoveObject(player);
			exit(0);
		}
	}
}

void Alien::CheckBorderHorizontal()
{
	if (m_pos.x < 0 || m_pos.x >= GetGame()->m_bounds.x - m_velocity)
	{
		m_direction = -m_direction;
		m_pos.y += m_velocity;
	}
}

float Alien::GetDirection() const
{
	return m_direction;
}

void Alien::Update()
{
	CheckBorderHorizontal();
	CheckBorderVertical();
	m_pos.x += m_direction * m_velocity;

	GameRand::floatRand fireRate(0, 1);
	if (fireRate(GameRand::GetInstance()->rGen) < 0.5f && GetGame()->m_AlienLasers > 0)
	{
		//Spawn laser
		GameObject& newLaser = *new AlienLaser;
		newLaser.m_pos = m_pos;
		GetGame()->SpawnLaser(&newLaser);
	}
}