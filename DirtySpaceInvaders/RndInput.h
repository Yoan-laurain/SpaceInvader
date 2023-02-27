#pragma once

#include "Input.h"

class RndInput : public Input
{
	public:
		virtual bool Left() override;
		virtual bool Right() override;
		virtual bool Fire() override;
};