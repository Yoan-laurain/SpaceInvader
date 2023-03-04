#include "ConsoleRenderer.h"
#include <thread>
#include "PlayField.h"

PlayField* g_playField = nullptr;

PlayField* GetGame()
{
	return g_playField;
}

int main()
{
	sf::Vector2f size(80, 28);
	Renderer consoleRenderer(size);
	
	g_playField = new PlayField(size);

	g_playField->Start();

	while(true)    
	{
		g_playField->Update(); 
		 
		consoleRenderer.Update();

		// Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}