#include "PlayerShip.h"
#include "PlayerLaser.h"
#include "ConsoleRenderer.h"
#include "PlayField.h"

PlayerShip::PlayerShip()
{
	m_objType = new char[64];
	strcpy(m_objType, "PlayerShip");
	m_sprite = RS_Player;
}

PlayerShip::~PlayerShip()
{
	if (m_objType)
		delete m_objType;
}

void PlayerShip::Update(PlayField& world)
{
	if (world.m_controllerInput->Left())
		m_pos.x -= m_speed;
	else if (world.m_controllerInput->Right())
		m_pos.x += m_speed;

	if (world.m_controllerInput->Fire() && world.m_PlayerLasers > 0)
	{
		//Spawn laser
		GameObject& newLaser = *(new PlayerLaser);
		newLaser.m_pos = m_pos;
		world.SpawnLaser(&newLaser);
	}
}

bool PlayerShip::DecreaseHealth(float damage)
{
	m_health -= damage;
	return m_health <= 0;
}