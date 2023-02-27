#include "Alien.h"
#include "AlienLaser.h"
#include "PlayerField.h"
#include "GameRand.h"

Alien::Alien()
{
	m_objType = new char[64];
	strcpy(m_objType, "Alien");
	sprite = RS_Alien;
}

Alien::~Alien()
{
	delete[] m_objType;
}

bool Alien::DecreaseHealth()
{
	m_health -= 1.f; 
	return m_health <= 0;
}

void Alien::Update(PlayField& world)
{
	pos.x += m_direction * m_velocity;
	// Border check
	if (pos.x < 0 || pos.x >= world.m_bounds.x - 1)
	{
		m_direction = -m_direction;
		pos.y += 1;
	}

	// Border check vertical:
	if (pos.y >= world.m_bounds.y - 1)
	{
		// kill player
		GameObject* player = world.GetPlayerObject();
		
		if (player == nullptr)
		{
			throw std::invalid_argument("Player object is null");
			return;
		}
		
		if (pos.IntCmp(player->pos))
		{
			world.RemoveObject(player);
			exit(0);
		}
	}

	GameRand::floatRand fireRate(0, 1);
	if (fireRate(GameRand::GetInstance()->rGen) < 0.5 && world.m_AlienLasers > 0)
	{
		//Spawn laser
		GameObject& newLaser = *(new AlienLaser);
		newLaser.pos = pos;
		world.SpawnLaser(&newLaser);
	}
}