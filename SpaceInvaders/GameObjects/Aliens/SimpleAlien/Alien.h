#pragma once

#include "../SpaceInvaders/GameObjects/GameObject.h"

class Alien : public GameObject
{
	public:
		Alien();
		~Alien() override;

		virtual bool DecreaseHealth(float damage) override;

		void CheckBorderVertical(PlayField& world);
		void CheckBorderHorizontal(PlayField& world);

		float GetDirection();

	protected:
		float m_health = 1.f;
		float m_energy = 0.f;
		float m_direction = 1.f;
		float m_velocity = 0.3f;

		void Update(PlayField& world) override;
};