#pragma once

#include "../Utils/GameRand.h"
#include "Utils/Vector2D.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <stdexcept>

class PlayField;

enum RaiderSprites
{
	RS_BackgroundTile = ' ',
	RS_Player = 'P',
	RS_Alien = 'A',
	RS_BetterAlien = 'B',
	RS_PlayerLaser = 0xBA,
	RS_AlienLaser = '|',
	RS_Explosion = '*',
	RS_Rock = '#'
};


class GameObject
{
	public:
		GameObject();
		virtual ~GameObject();

		char* m_objType = nullptr;
		Vector2D m_pos;
		RaiderSprites m_sprite;
		
		sf::Sprite m_sfmlSprite;
		sf::Texture m_texture;
		
		virtual void Update(PlayField& world);
		
		virtual bool DecreaseHealth(float damage);
};