#pragma once
#include "GameObject.h"

class PlayerLaser : public GameObject
{
	public:
		PlayerLaser();
		~PlayerLaser();

		void Update(PlayField& world) override;
};