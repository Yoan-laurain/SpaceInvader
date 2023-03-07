#pragma once

#include "Input.h"

class RndInput final : public Input
{
	public:
		bool Left() override;
		bool Right() override;
		bool Fire() override;
};