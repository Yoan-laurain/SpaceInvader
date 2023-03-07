#include "ConsoleRenderer.h"
#include "PlayField.h"
#include <vector>
#include <iostream>
#include <Windows.h>

void setCursorPosition(const int x, const int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();

	const COORD coord = 
		{
			static_cast<SHORT>(x),
			static_cast<SHORT>(y)
		};
	
	SetConsoleCursorPosition(hOut, coord);
}

ConsoleRenderer::ConsoleRenderer(const Vector2D& bounds)
	: IRenderer(bounds)
{
	canvasSize = static_cast<int>(bounds.x * bounds.y);
	disp[0].canvas = new unsigned char[canvasSize];
	disp[1].canvas = new unsigned char[canvasSize];
}

ConsoleRenderer::~ConsoleRenderer()
{
	delete[] disp[0].canvas;
	delete[] disp[1].canvas;
}

void ConsoleRenderer::Update(PlayField& world)
{
	FillCanvas( GetSprite( RS_BackgroundTile ) );

	for (const auto it : GetGame()->GameObjects())
	{
		if (nullptr == it)
			continue;

		const int x = static_cast<int>(it->m_pos.x);
		const int y = static_cast<int>(it->m_pos.y);

		if (x >= 0 && x < m_bounds.x && y >= 0 && y < m_bounds.y)
		{
			*CurCanvas(x, y) = GetSprite(it->m_sprite);
		}
	}
}

unsigned char* ConsoleRenderer::CurCanvas(int x, int y)
{
	return &disp[curIdx % 2].canvas[x + static_cast<int>(m_bounds.x) * y];
}

void ConsoleRenderer::FillCanvas(const unsigned char sprite)
{
	for (int i = 0; i < canvasSize; i++)
	{
		*CurCanvas(i, 0) = sprite;
	}
}

void ConsoleRenderer::Draw()
{
	for (int y = 0; y < m_bounds.y; y++)
	{
		for (int x = 0; x < m_bounds.x; x++)
		{
			setCursorPosition(x, y);
			std::cout << *CurCanvas(x, y);
		}
		std::cout << std::endl;
	}

	curIdx++;
}

const unsigned char ConsoleRenderer::GetSprite(const RaiderSprites& sprite) const
{
	switch (sprite)
	{
		case RS_BackgroundTile:
			return ' ';
		case RS_Player: 
			return 'P';
		case RS_Alien:
			return 'A';
		case RS_BetterAlien:
			return 'B';
		case RS_PlayerLaser:
			return 0xBA;
		case RS_AlienLaser:
			return '|';
		case RS_Explosion:
			return '*';
		case RS_Rock:
			return '#';
		default:
			return ' ';	
	}
}
