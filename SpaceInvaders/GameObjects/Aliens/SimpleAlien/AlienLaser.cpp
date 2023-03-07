#include "AlienLaser.h"
#include "Renderer/ConsoleRenderer/ConsoleRenderer.h"
#include "PlayField.h"
#include "GameObjects/Player/PlayerShip.h"

AlienLaser::AlienLaser()
{
	m_objType = new char[64]; 
	strcpy(m_objType, "AlienLaser");
	m_sprite = RS_AlienLaser;

	if (!m_texture.loadFromFile("Ressources/AlienLaser.png"))
	{
		throw std::invalid_argument("Could not load texture");
	}

	m_sfmlSprite.setTexture(m_texture);
}

AlienLaser::~AlienLaser()
{
	delete[] m_objType;
}

void AlienLaser::Update()
{
	bool deleted = false;
	m_pos.y += m_laserSpeed;

	if (m_pos.y > GetGame()->m_bounds.y)
		deleted = true;

	if ( CheckCollisionWithRock() )
		deleted = true;

	if ( CheckCollisionWithPlayer() ) 
		deleted = true;

	if (deleted)
		GetGame()->DespawnLaser(this);
}

// TODO : OPTI
bool AlienLaser::CheckCollisionWithRock()
{
	for ( const auto it : GetGame()->GameObjects())
		if ( nullptr != it)
			if (!strcmp(it->m_objType, "Rock"))
				if (it->m_pos.IntCmp(m_pos))
					return true;
				
	return false;
}

bool AlienLaser::CheckCollisionWithPlayer()
{
	GameObject* player = GetGame()->GetPlayerObject();

	if (nullptr == player)
		return false;
	
	if (m_pos.IntCmp(player->m_pos))
	{
		const auto p = static_cast<PlayerShip*>(player);

		if (nullptr == p)
			return false;

		if (p->DecreaseHealth(m_laserDamage))
		{
			GetGame()->RemoveObject(player);
			exit(0);
		}

		return true;
	}

	return false;
}