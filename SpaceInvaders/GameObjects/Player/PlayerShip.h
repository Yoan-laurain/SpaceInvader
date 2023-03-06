#pragma once

#include "../SpaceInvaders/GameObjects/GameObject.h"
#include "../SpaceInvaders/SFMLInputs/InputAction.h"
#include <functional>

class PlayerShip : public GameObject
{
	public:
		PlayerShip();
		~PlayerShip();

		void Start();

		void Update(PlayField& world) override;
		virtual bool DecreaseHealth(float damage) override;

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