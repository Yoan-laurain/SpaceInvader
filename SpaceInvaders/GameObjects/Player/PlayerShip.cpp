#include "PlayerShip.h"
#include "PlayerLaser.h"
#include "../SpaceInvaders/Renderer/ConsoleRenderer.h"
#include "PlayField.h"


PlayerShip::PlayerShip()
{
	m_objType = new char[64];
	strcpy(m_objType, "PlayerShip");
	m_sprite = RS_Player;

	if (!m_texture.loadFromFile("Ressources/PlayerShip.png"))
	{
		throw std::invalid_argument("Could not load texture");
	}

	m_sfmlSprite.setTexture(m_texture);
}

PlayerShip::~PlayerShip()
{
	if (m_objType)
		delete m_objType;
}

void PlayerShip::Start()
{
	BindFunctionToInputAction(InputAction::Left, std::bind(&PlayerShip::Left, this,std::placeholders::_1, -1.f));
	BindFunctionToInputAction(InputAction::Right, std::bind(&PlayerShip::Right, this, std::placeholders::_1, 1.f));
	BindFunctionToInputAction(InputAction::Fire, std::bind(&PlayerShip::Fire, this, std::placeholders::_1));
}

void PlayerShip::Update(PlayField& world) {}

bool PlayerShip::DecreaseHealth(float damage)
{
	m_health -= damage;
	return m_health <= 0;
}

void PlayerShip::Left(float value, float sign)
{
	if ( m_pos.x + (value * sign) * m_speed < 0 )
	{
		return;
	}
	m_pos.x += (value * sign) * m_speed;
}

void PlayerShip::Right(float value, float sign)
{
	if (m_pos.x + (value * sign) * m_speed >= GetGame()->m_bounds.x)
	{
		return;
	}
	m_pos.x += (value * sign) * m_speed;
}

void PlayerShip::Fire(float value)
{
	if (value == 0)
	{
		return;
	}
	
	if (GetGame()->m_PlayerLasers > 0)
	{
		//Spawn laser
		GameObject& newLaser = *(new PlayerLaser);
		newLaser.m_pos = m_pos;
		GetGame()->SpawnLaser(&newLaser);
	}
}

void PlayerShip::BindFunctionToInputAction(InputAction inputAction, std::function<void(float)> func)
{
	GetGame()->BindAction(this, inputAction, func);
}
