#pragma once

#include "GameObjects/Aliens/SimpleAlien/Alien.h"

class BetterAlien final : public Alien
{
	public:
		BetterAlien();

		void SetDirection(float iDirection);
};