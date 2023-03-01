#pragma once

#include "GameObject.h"

class Alien : public GameObject
{
	public:
		Alien();
		~Alien();

		virtual bool DecreaseHealth(float damage) override;

		void CheckBorderVertical(PlayField& world);
		void CheckBorderHorizontal(PlayField& world);

	protected:
		float m_health = 1.f;
		float m_energy = 0.f;
		float m_direction = 1.f;
		float m_velocity = 0.5f;

		void Update(PlayField& world) override;
};