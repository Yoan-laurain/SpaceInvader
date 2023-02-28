#include "ConsoleRenderer.h"
#include <thread>
#include <memory>
#include <string>
#include "PlayerField.h"
#include "Alien.h"
#include "PlayerShip.h"
#include "GameRand.h"
#include "Rock.h"
#include "BetterAlien.h"

int main()
{
	GameRand* gameRandInstance = GameRand::GetInstance();
	
	gameRandInstance->rGen.seed(1);

	sf::Vector2f size(80, 28);
	Renderer consoleRenderer(size);
	PlayField world(size);

	GameRand::intRand xCoord(0, (int)size.x- 1);
	GameRand::intRand yCoord(0, 10);

	//Populate aliens
	for (int k = 0; k < world.m_alienCount; k++)
	{
		Alien& a = *(new Alien);
		a.pos.x = (float)xCoord(gameRandInstance->rGen);
		a.pos.y = (float)yCoord(gameRandInstance->rGen);
		world.AddObject(&a);
	}

	GameRand::intRand xCoorRock(0, (int)size.x - 1);
	GameRand::intRand yCoordRock(10, 15);
	
	// populate rocks
	for (int k = 0; k < world.m_rockCount; k++)
	{
		Rock& a = *(new Rock);
		a.pos.x = (float)xCoorRock(gameRandInstance->rGen);
		a.pos.y = (float)yCoordRock(gameRandInstance->rGen);
		world.AddObject(&a);
	}

	// Add player
	PlayerShip* p = new PlayerShip;
	p->pos = sf::Vector2f(40, 27);
	world.AddObject(p);

	while(true)    
	{
		world.Update();
		 
		RenderItemList rl;
		for (auto it : world.GameObjects())
		{
			RenderItem a = RenderItem(sf::Vector2f(it->pos), it->sprite);
			rl.push_back(a);
		}

		consoleRenderer.Update(rl);

		// Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}