#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>

struct RenderItem
{
	RenderItem(const sf::Vector2f& iPos, char iSprite) : pos(iPos), sprite(iSprite) {};
	sf::Vector2f pos;
	char sprite;
};
typedef std::vector<RenderItem> RenderItemList;

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

class Renderer
{
public:
	Renderer(const sf::Vector2f& bounds);
	~Renderer();

	// Draws all game objects after clearing filling the Canvas with _ symbol
	void Update();

private:
	sf::Vector2f renderBounds;
	int curIdx = 0;

	struct
	{
		unsigned char* canvas = nullptr;
	} disp[2]; // double buffer our canvas for no flicker display

	int canvasSize = 0;
	unsigned char* CurCanvas(int x, int y);

	// Fills whole canvas array with sprite
	void FillCanvas(unsigned char sprite);

	// Prints canvas char array on console
	void DrawCanvas();
};