#pragma once

#include "GameObject.h"

class AlienLaser : public GameObject
{
	public:
		AlienLaser();
		~AlienLaser();

		void Update(PlayField& world) override;
		
		bool CheckCollisionWithRock(PlayField& world);
		
		bool CheckCollisionWithPlayer(PlayField& world);

	private : 

		int m_laserSpeed = 1.f;
		int m_laserDamage = 1.f;
};