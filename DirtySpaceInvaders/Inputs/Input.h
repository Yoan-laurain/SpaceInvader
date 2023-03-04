#pragma once

class Input
{
	public:	
		virtual ~Input() = default;
		virtual bool Left() = 0;
		virtual bool Right() = 0;
		virtual bool Fire() = 0;
};