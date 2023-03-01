#include "ConsoleRenderer.h"
#include <thread>
#include <memory>
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
		 
		RenderItemList rl;
		for (auto it : g_playField->GameObjects()) 
		{
			RenderItem a = RenderItem(sf::Vector2f(it->m_pos), it->m_sprite);
			rl.push_back(a);
		}

		consoleRenderer.Update(rl);

		// Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}