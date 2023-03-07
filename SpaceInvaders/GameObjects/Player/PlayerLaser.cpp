#include "PlayerLaser.h"
#include  "Renderer/ConsoleRenderer/ConsoleRenderer.h"
#include "PlayField.h"

PlayerLaser::PlayerLaser()
{
	m_objType = new char[64]; 
	strcpy(m_objType, "PlayerLaser"); 
	m_sprite = RS_PlayerLaser;

	if (!m_texture.loadFromFile("Ressources/LaserPlayer.png"))
	{
		throw std::invalid_argument("Could not load texture");
	}

	m_sfmlSprite.setTexture(m_texture);
}

PlayerLaser::~PlayerLaser()
{
	if (m_objType != nullptr)
		delete[] m_objType;
}

// TODO : OPTI
void PlayerLaser::Update()
{
	// if out of the map
	bool deleted = false;
	m_pos.y -= m_laserSpeed;

	if (m_pos.y < 0)
		deleted = true;

	// if hit alien
	for (const auto it : GetGame()->GameObjects())
	{
		if (nullptr == it) continue;
		
		if (deleted)
			break;
		
		if ( !strcmp(it->m_objType, "Alien") )
		{
			if ( it->m_pos.IntCmp(m_pos) )
			{				
				CollisionWithAlien( it);			
				deleted = true;
			}
		}
		else if (!strcmp(it->m_objType, "AlienLaser"))
		{
			if (it->m_pos.IntCmp(m_pos))
			{
				GetGame()->DespawnLaser(it);
				deleted = true;
			}
		}
		else if (!strcmp(it->m_objType, "Rock"))
		{
			if (it->m_pos.IntCmp(m_pos))
			{
				deleted = true;
			}
		}	
	}

	if (deleted)
		GetGame()->DespawnLaser(this);
}

void PlayerLaser::CollisionWithAlien(GameObject* alien)
{
	if (nullptr == alien) return;
	
	if ( alien->DecreaseHealth(m_laserDamage) )
		GetGame()->RemoveObject(alien);
}