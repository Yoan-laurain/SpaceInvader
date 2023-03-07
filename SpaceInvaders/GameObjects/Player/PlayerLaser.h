#pragma once

#include "GameObjects/GameObject.h"

class PlayerLaser final : public GameObject
{
	public:
		PlayerLaser();
		~PlayerLaser() override;

		void Update() override;

		void CollisionWithAlien(GameObject* alien);

	private:
		float m_laserSpeed = 1.f;
		float m_laserDamage = 1.f;
};