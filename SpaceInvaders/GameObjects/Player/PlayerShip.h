#pragma once

#include "GameObjects/GameObject.h"
#include "Inputs/SFMLInputs/InputAction.h"

#include <functional>

class PlayerShip final : public GameObject
{
	public:
		PlayerShip();
		~PlayerShip() override;

		void Start();

		void Update() override;
		bool DecreaseHealth(float damage) override;

		void Left(float value, float sign);
		void Right(float value, float sign);
		void Fire(float value);

	private :
		int m_health = 50;
		int m_speed = 1;
		int m_laserDamage = 1;

	protected:
		void BindFunctionToInputAction(InputAction inputAction, std::function<void(float)> func);
};