#include "ConsoleRenderer.h"
#include <thread>
#include <memory>
#include "PlayField.h"

int main()
{
	sf::Vector2f size(80, 28);
	Renderer consoleRenderer(size);
	PlayField world(size);

	while(true)    
	{
		world.Update();
		 
		RenderItemList rl;
		for (auto it : world.GameObjects())
		{
			RenderItem a = RenderItem(sf::Vector2f(it->m_pos), it->m_sprite);
			rl.push_back(a);
		}

		consoleRenderer.Update(rl);

		// Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}