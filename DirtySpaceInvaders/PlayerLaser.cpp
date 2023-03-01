#include "PlayerLaser.h"
#include "ConsoleRenderer.h"
#include "PlayField.h"
#include "Alien.h"

PlayerLaser::PlayerLaser()
{
	m_objType = new char[64]; 
	strcpy(m_objType, "PlayerLaser"); 
	m_sprite = RS_PlayerLaser;
}

PlayerLaser::~PlayerLaser()
{
	if (m_objType != nullptr)
		delete[] m_objType;
}

// TODO : OPTI
void PlayerLaser::Update(PlayField& world)
{
	// if out of the map
	bool deleted = false;
	m_pos.y -= m_laserSpeed;

	if (m_pos.y < 0)
		deleted = true;

	// if hit alien
	for (auto it : world.GameObjects())
	{
		if (deleted)
			break;
		else if ( !strcmp(it->m_objType, "Alien") )
		{
			if ( it->IntCmp(m_pos) )
			{				
				CollisionWithAlien(world, it);			
				deleted = true;
			}
		}
		else if (!strcmp(it->m_objType, "AlienLaser"))
			if ( it->IntCmp(m_pos) )
			{
				world.DespawnLaser(it);
				deleted = true;
			}
		else if (!strcmp(it->m_objType, "Rock"))
			if ( it->IntCmp(m_pos) )
				deleted = true;
	}

	if (deleted)
		world.DespawnLaser(this);
}

void PlayerLaser::CollisionWithAlien(PlayField& world, GameObject* alien)
{
	Alien* alienHit = (Alien*)alien;
	bool isDead = alienHit->DecreaseHealth(m_laserDamage);

	if (isDead)
		world.RemoveObject(alienHit);
}