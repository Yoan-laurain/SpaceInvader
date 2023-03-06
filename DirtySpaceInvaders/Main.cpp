#include <thread>

#include "../DirtySpaceInvaders/Renderer/ConsoleRenderer.h"
#include "PlayField.h"

#define RenderMode 0

#if RenderMode == 0
#include "SFMLRenderer.h"
#elif RenderMode == 1
#include "Renderer/ConsoleRenderer.h"
#endif

PlayField* g_playField = nullptr;

PlayField* GetGame()
{
	return g_playField;
}

int main()
{
	Vector2D size(80,45);

#if RenderMode == 0
	IRenderer* consoleRenderer = new SFMLRenderer(size,16);
#elif RenderMode == 1
	IRenderer* consoleRenderer = new ConsoleRenderer(size);
#endif

	g_playField = new PlayField(size);

	if (nullptr == g_playField)
		return -1;

	g_playField->Start();

	while(true)
	{		
		g_playField->Update(); 
		 
		consoleRenderer->Update(*g_playField);
		consoleRenderer->Draw();

		// Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	delete g_playField;

	return 0;
}