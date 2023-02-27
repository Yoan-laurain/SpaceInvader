#pragma once
#include "GameObject.h"

class Alien : public GameObject
{
	public:
		Alien();
		~Alien();

	private:
		float m_health = 1.f;
		float m_energy = 0.f;
		float m_direction = 1.f;
		float m_velocity = 0.5f;

		bool DecreaseHealth();

		void Update(PlayField& world) override;
};