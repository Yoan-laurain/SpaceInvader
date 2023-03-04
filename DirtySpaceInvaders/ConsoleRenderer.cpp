#include <vector>
#include <iostream>
#include "ConsoleRenderer.h"
#include <Windows.h>
#include <PlayField.h>

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	
	COORD coord = 
		{
			(SHORT)x,
			(SHORT)y
		};
	
	SetConsoleCursorPosition(hOut, coord);
}

Renderer::Renderer(const sf::Vector2f& bounds)
	: renderBounds(bounds)
{
	canvasSize = (int)(bounds.x * bounds.y);
	disp[0].canvas = new unsigned char[canvasSize];
	disp[1].canvas = new unsigned char[canvasSize];
}


Renderer::~Renderer()
{
	delete[] disp[0].canvas;
	delete[] disp[1].canvas;
}

void Renderer::Update()
{
	FillCanvas(RS_BackgroundTile);

	for (auto it : GetGame()->GameObjects())
	{
		int x = int(it->m_pos.x);
		int y = int(it->m_pos.y);

		if (x >= 0 && x < renderBounds.x && y >= 0 && y < renderBounds.y)
		{
			*CurCanvas((int)it->m_pos.x, +(int)it->m_pos.y) = it->m_sprite;
		}
	}

	DrawCanvas();
}

unsigned char* Renderer::CurCanvas(int x, int y)
{
	return &disp[curIdx % 2].canvas[x + (int)renderBounds.x * y];
}

void Renderer::FillCanvas(unsigned char sprite)
{
	for (int i = 0; i < canvasSize; i++)
	{
		*CurCanvas(i, 0) = sprite;
	}
}

void Renderer::DrawCanvas()
{
	for (int y = 0; y < renderBounds.y; y++)
	{
		for (int x = 0; x < renderBounds.x; x++)
		{
			setCursorPosition(x, y);
			std::cout << *CurCanvas(x, y);
		}
		std::cout << std::endl;
	}

	curIdx++;
}