#pragma once

#include "GameObject.h"

class PlayerShip : public GameObject
{
	public:
		PlayerShip();
		~PlayerShip();

		void Update(PlayField& world) override;
		virtual bool DecreaseHealth(float damage) override;

	private :
		int m_health = 50;
		int m_speed = 1;
		int m_laserDamage = 1;
};