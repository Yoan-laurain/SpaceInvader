#include <thread>
#include "PlayField.h"

#define RenderMode 0

#if RenderMode == 0
#include "Renderer/SFMLRenderer/SFMLRenderer.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
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
	Vector2D size(40, 25);

#if RenderMode == 0
	IRenderer* consoleRenderer = new SFMLRenderer(size, 32);
#elif RenderMode == 1
	IRenderer* consoleRenderer = new ConsoleRenderer(size);
#endif

	g_playField = new PlayField(size);

	if (nullptr == g_playField)
		return -1;

	g_playField->Start();

#if RenderMode == 1	
	while (true)
	{ 
#elif RenderMode == 0
	sf::RenderWindow& window = static_cast<SFMLRenderer*>(consoleRenderer)->GetWindow();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
#endif

		g_playField->Update();

		consoleRenderer->Update(*g_playField);
		consoleRenderer->Draw();

		// Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
	}

	delete g_playField;

	return 0;
}