#include "PlayerLaser.h"
#include "ConsoleRenderer.h"
#include "PlayerField.h"
#include "Alien.h"

PlayerLaser::PlayerLaser()
{
	m_objType = new char[64]; 
	strcpy(m_objType, "PlayerLaser"); 
	sprite = RS_PlayerLaser;
}

PlayerLaser::~PlayerLaser()
{
	if (m_objType != nullptr)
	{
		delete[] m_objType;
	}
}

void PlayerLaser::Update(PlayField& world)
{
	// if out of the map
	bool deleted = false;
	pos.y -= 1.f;

	if (pos.y < 0)
	{
		deleted = true;
	}
	
	// if hit alien
	for (auto it : world.GameObjects())
	{
		if ( !strcmp(it->m_objType, "Alien") )
		{
			if (it->pos.IntCmp(pos))
			{				
				Alien* alien = (Alien*)it;
				bool isDead = alien->DecreaseHealth();

				if (isDead)
				{
					world.RemoveObject(it);
				}
				
				deleted = true;
				break;
			}
		}
		else if (!strcmp(it->m_objType, "AlienLaser"))
		{
			if (it->pos.IntCmp(pos))
			{
				world.DespawnLaser(it);

				deleted = true;
				break;
			}
		}
	}

	if (deleted)
	{
		world.DespawnLaser(this);
	}
}