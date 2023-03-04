#include "BetterAlien.h"
#include "ConsoleRenderer.h"

BetterAlien::BetterAlien() : Alien()
{
	m_health = 2.f;
	m_energy = 1.f;
	m_velocity = 1.7f;
	m_sprite = RS_BetterAlien;	
}

void BetterAlien::SetDirection(float iDirection)
{
	m_direction = iDirection; 
}

