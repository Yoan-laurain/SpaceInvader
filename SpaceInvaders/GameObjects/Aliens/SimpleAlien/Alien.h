#pragma once

#include "GameObjects/GameObject.h"

class Alien : public GameObject
{
	public:
		Alien();
		~Alien() override;

		bool DecreaseHealth(float damage) override;

		void CheckBorderVertical();
		void CheckBorderHorizontal();

		float GetDirection() const;

	protected:
		float m_health = 1.f;
		float m_energy = 0.f;
		float m_direction = 1.f;
		float m_velocity = 0.3f;

		void Update() override;
};