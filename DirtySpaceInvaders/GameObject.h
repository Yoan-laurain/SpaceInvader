#pragma once

#include <SFML/System/Vector2.hpp>

class PlayField;

class GameObject
{
	public:
		char* m_objType = nullptr;
		sf::Vector2f pos;
		unsigned char sprite;
		
		bool IntCmp(const  sf::Vector2f& vec);

		virtual void Update(PlayField& world);
		virtual bool DecreaseHealth();
};