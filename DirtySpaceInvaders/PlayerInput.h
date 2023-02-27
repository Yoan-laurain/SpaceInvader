#pragma once

#include "Input.h"

class PlayerInput : public Input
{
	public:
		virtual bool Left() override;
		virtual bool Right() override;
		virtual bool Fire() override;

	private:
		bool haveFired;
};