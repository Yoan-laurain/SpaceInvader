#include "BetterAlien.h"


BetterAlien::BetterAlien() : Alien()
{
	m_health = 2.f;
	m_energy = 1.f;
	m_velocity = 1.5f;
	sprite = RS_BetterAlien;
}

BetterAlien::~BetterAlien() 
{
	
}
