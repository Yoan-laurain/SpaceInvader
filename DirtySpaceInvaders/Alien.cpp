#include "Alien.h"
#include "AlienLaser.h"
#include "PlayField.h"
#include "GameRand.h"
#include <ConsoleRenderer.h>

Alien::Alien()
{
	m_objType = new char[64];
	strcpy(m_objType, "Alien");
	m_sprite = RS_Alien;
}

Alien::~Alien()
{
	delete[] m_objType;
}

bool Alien::DecreaseHealth(float damage)
{
	m_health -= damage; 
	return m_health <= 0;
}

void Alien::CheckBorderVertical(PlayField& world)
{
	if ( m_pos.y >= world.m_bounds.y - m_velocity)
	{
		// kill player 
		GameObject* player = world.GetPlayerObject(); 

		if (player == nullptr)
		{
			throw std::invalid_argument("Player object is null");
			return;
		}

		if ( m_pos.y >= player->m_pos.y && m_pos.x >= player->m_pos.x || m_pos.y >= world.m_bounds.y)
		{
			world.RemoveObject(player);
			exit(0);
		}
	}
}

void Alien::CheckBorderHorizontal(PlayField& world)
{
	if (m_pos.x < 0 || m_pos.x >= world.m_bounds.x - m_velocity)
	{
		m_direction = -m_direction;
		m_pos.y += m_velocity;
	}
}

void Alien::Update(PlayField& world)
{
	CheckBorderHorizontal(world);
	CheckBorderVertical(world);
	m_pos.x += m_direction * m_velocity;

	GameRand::floatRand fireRate(0, 1);
	if (fireRate(GameRand::GetInstance()->rGen) < 0.5 && world.m_AlienLasers > 0)
	{
		//Spawn laser
		GameObject& newLaser = *(new AlienLaser);
		newLaser.m_pos = m_pos;
		world.SpawnLaser(&newLaser);
	}
}