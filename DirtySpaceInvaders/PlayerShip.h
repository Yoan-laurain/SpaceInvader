#pragma once

#include "GameObject.h"

class PlayerShip : public GameObject
{
	public:
		PlayerShip();
		~PlayerShip();

		void Update(PlayField& world) override;
		virtual bool DecreaseHealth() override;

	private :
		int m_health = 1;
};