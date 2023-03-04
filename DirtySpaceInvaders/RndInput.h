#pragma once

#include "Input.h"

class RndInput : public Input
{
	public:
		bool Left() override;
		bool Right() override;
		bool Fire() override;
};