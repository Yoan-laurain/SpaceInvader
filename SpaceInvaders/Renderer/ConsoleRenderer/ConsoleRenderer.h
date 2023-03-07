#pragma once

#include "Renderer/IRenderer.h"
#include "GameObjects/GameObject.h"

class ConsoleRenderer : public IRenderer
{
public:
	ConsoleRenderer(const Vector2D& bounds);
	~ConsoleRenderer() override;

	// Draws all game objects after clearing filling the Canvas with _ symbol
	void Update(PlayField& world) override;
	
	void Draw() override;

private:
	int curIdx = 0;

	struct
	{
		unsigned char* canvas = nullptr;
	} disp[2]; // double buffer our canvas for no flicker display

	int canvasSize = 0;
	unsigned char* CurCanvas(int x, int y);

	// Fills whole canvas array with sprite
	void FillCanvas(unsigned char sprite);

	const unsigned char GetSprite(const RaiderSprites& sprite) const;
};