#pragma once

#include "../DirtySpaceInvaders/GameObjects/GameObject.h"

class AlienLaser : public GameObject
{
	public:
		AlienLaser();
		~AlienLaser() override;

		void Update(PlayField& world) override;
		
		bool CheckCollisionWithRock(PlayField& world);
		
		bool CheckCollisionWithPlayer(PlayField& world);

	private : 

		int m_laserSpeed = 1.f;
		int m_laserDamage = 1.f;
};