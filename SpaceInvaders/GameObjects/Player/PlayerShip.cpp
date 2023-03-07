#include "PlayerShip.h"
#include "PlayerLaser.h"
#include "Renderer/ConsoleRenderer/ConsoleRenderer.h"
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
	delete m_objType;
}

/*
* Brief : Bind a function to the input action
*/
void PlayerShip::Start()
{
	BindFunctionToInputAction(InputAction::Left, std::bind(&PlayerShip::Left, this,std::placeholders::_1, -1.f));
	BindFunctionToInputAction(InputAction::Right, std::bind(&PlayerShip::Right, this, std::placeholders::_1, 1.f));
	BindFunctionToInputAction(InputAction::Fire, std::bind(&PlayerShip::Fire, this, std::placeholders::_1));
}

void PlayerShip::Update() {}

bool PlayerShip::DecreaseHealth(const float damage)
{
	m_health -= damage;
	return m_health <= 0;
}

void PlayerShip::Left(const float value, const float sign)
{
	if ( m_pos.x + value * sign * m_speed < 0 )
	{
		return;
	}
	m_pos.x += value * sign * m_speed;
}

void PlayerShip::Right(const float value, const float sign)
{
	if (m_pos.x + value * sign * m_speed >= GetGame()->m_bounds.x)
	{
		return;
	}
	m_pos.x += value * sign * m_speed;
}

void PlayerShip::Fire(const float value)
{
	if (value == 0.f)
	{
		return;
	}
	
	if (GetGame()->m_PlayerLasers > 0)
	{
		//Spawn laser
		GameObject& newLaser = *new PlayerLaser;
		newLaser.m_pos = m_pos;
		GetGame()->SpawnLaser(&newLaser);
	}
}

void PlayerShip::BindFunctionToInputAction(const InputAction inputAction, const std::function<void(float)> func)
{
	GetGame()->BindAction(this, inputAction, func);
}
