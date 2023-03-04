#pragma once

#include "../DirtySpaceInvaders/GameObjects/GameObject.h"

class PlayerLaser : public GameObject
{
	public:
		PlayerLaser();
		~PlayerLaser();

		void Update(PlayField& world) override;

		void CollisionWithAlien(PlayField& world, GameObject* alien);

	private:
		int m_laserSpeed = 1.f;
		int m_laserDamage = 1.f;
};