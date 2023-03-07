#pragma once

#include "GameObjects/Aliens/SimpleAlien/Alien.h"

class BetterAlien : public Alien
{
	public:
		BetterAlien();

		void SetDirection(float iDirection);
};