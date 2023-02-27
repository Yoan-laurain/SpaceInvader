#include "PlayerShip.h"
#include "PlayerLaser.h"
#include "ConsoleRenderer.h"
#include "PlayerField.h"

PlayerShip::PlayerShip()
{
	m_objType = new char[64];
	strcpy(m_objType, "PlayerShip");
	sprite = RS_Player;
}

PlayerShip::~PlayerShip()
{
	delete m_objType;
}

void PlayerShip::Update(PlayField& world)
{
	if (world.m_controllerInput->Left())
		pos.x -= 1;
	else if (world.m_controllerInput->Right())
		pos.x += 1;

	if (world.m_controllerInput->Fire() && world.m_PlayerLasers > 0)
	{
		//Spawn laser
		GameObject& newLaser = *(new PlayerLaser);
		newLaser.pos = pos;
		world.SpawnLaser(&newLaser);
	}
}
