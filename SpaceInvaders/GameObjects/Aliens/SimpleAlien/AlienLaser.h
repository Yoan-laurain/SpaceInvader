#pragma once

#include "GameObjects/GameObject.h"

class AlienLaser final : public GameObject
{
	public:
		AlienLaser();
		~AlienLaser() override;

		void Update() override;
		
		bool CheckCollisionWithRock();
		
		bool CheckCollisionWithPlayer();

	private : 

		float m_laserSpeed = 1.f;
		float m_laserDamage = 1.f;
};