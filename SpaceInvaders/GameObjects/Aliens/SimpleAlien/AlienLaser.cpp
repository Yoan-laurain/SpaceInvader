#include "AlienLaser.h"
#include "../SpaceInvaders/Renderer/ConsoleRenderer.h"
#include "PlayField.h"
#include "../SpaceInvaders/GameObjects/Player/PlayerShip.h"

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

void AlienLaser::Update(PlayField& world)
{
	bool deleted = false;
	m_pos.y += m_laserSpeed;

	if (m_pos.y > world.m_bounds.y)
		deleted = true;

	if ( CheckCollisionWithRock(world) )
		deleted = true;

	if ( CheckCollisionWithPlayer(world) ) 
		deleted = true;

	if (deleted)
		world.DespawnLaser((GameObject*)this);
}

// TODO : OPTI
bool AlienLaser::CheckCollisionWithRock(PlayField& world)
{
	for (auto it : world.GameObjects())
		if ( nullptr != it)
			if (!strcmp(it->m_objType, "Rock"))
				if (it->m_pos.IntCmp(m_pos))
					return true;
				
	return false;
}

bool AlienLaser::CheckCollisionWithPlayer(PlayField& world)
{
	GameObject* player = world.GetPlayerObject();

	if (nullptr == player)
		return false;
	
	if (m_pos.IntCmp(player->m_pos))
	{
		PlayerShip* p = (PlayerShip*)player;

		if (nullptr == p)
			return false;
		
		bool isDead = p->DecreaseHealth(m_laserDamage);

		if (isDead)
		{
			world.RemoveObject(player);
			exit(0);
		}

		return true;
	}

	return false;
}