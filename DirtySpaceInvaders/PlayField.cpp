#include "PlayField.h"
#include "PlayerInput.h"
#include "BetterAlien.h"
#include "Alien.h"
#include <GameRand.h>
#include <Rock.h>
#include <PlayerShip.h>
#include "PlayField.h"

PlayField::PlayField(sf::Vector2f iBounds) : m_bounds(iBounds)
{
	m_controllerInput = new PlayerInput;
	PopulateField();
}

const std::vector<GameObject*>& PlayField::GameObjects()
{
	return m_gameObjects;
}

void PlayField::Update()
{
	// Update list of active objects in the world
	for (auto it : m_gameObjects)
	{
		it->Update(*this);
	}

	for (auto it : m_gameObjectToAdd)
	{
		m_gameObjects.push_back(it);		
	}

	for (auto it : m_gameObjectToRemove)
	{
		delete it;
		m_gameObjects.erase(std::find(m_gameObjects.begin(), m_gameObjects.end(), it));
	}

	m_gameObjectToAdd.clear();
	m_gameObjectToRemove.clear();	  

	if (m_alienCount == 3)
		UpgradeAliens();
}

GameObject* PlayField::GetPlayerObject()
{
	auto it = std::find_if(m_gameObjects.begin(), m_gameObjects.end(), [](GameObject* in) 
		{
			// Maybe = 1 ?
			return (strcmp(in->m_objType, "PlayerShip") == 0);
		});

	if (it != m_gameObjects.end())
		return (*it);
	else
		return nullptr;
}

void PlayField::SpawnLaser(GameObject* newObj)
{
	if (strcmp(newObj->m_objType, "AlienLaser") == 0)
		m_AlienLasers--;

	else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
		m_PlayerLasers--;

	AddObject(newObj);
}

void PlayField::DespawnLaser(GameObject* newObj)
{
	if (strcmp(newObj->m_objType, "AlienLaser") == 0)
		m_AlienLasers++;

	else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
		m_PlayerLasers++;

	RemoveObject(newObj);
}

void PlayField::AddObject(GameObject* newObj)
{
	m_gameObjectToAdd.push_back(newObj);
}

void PlayField::RemoveObject(GameObject* newObj)
{
	auto it = std::find_if(m_gameObjects.begin(), m_gameObjects.end(), [&](GameObject* in) 
		{
			return (in == newObj);
		});

	if (it != m_gameObjects.end())
	{
		if (strcmp(newObj->m_objType, "Alien") == 0)
			m_alienCount--;

		else if (strcmp(newObj->m_objType, "Rock") == 0)
			m_rockCount--;
	}

	m_gameObjectToRemove.push_back(*it);
}

/*
* Brief : Upgrades all aliens to better aliens
*		  Loop through all game objects and check if they are aliens
*		  If they are, remove them and add a better alien instead
*/
void PlayField::UpgradeAliens()
{
	for (auto it : m_gameObjects)
	{
		if (strcmp(it->m_objType, "Alien") == 0)
		{
			Alien* alien = static_cast<Alien*>(it);
			
			BetterAlien* newAlien = new BetterAlien();
			newAlien->m_pos = alien->m_pos;
			
			RemoveObject(it);
			AddObject(newAlien);
		}
	}
}

/*
* Brief : Populates the field with aliens, rocks and the player
*/
void PlayField::PopulateField()
{
	GameRand* gameRandInstance = GameRand::GetInstance();
	gameRandInstance->rGen.seed(1);
	
	PopulateAliens();
	PopulateRocks();
	PopulatePlayer();
}

/*
* Brief : Populates the field with aliens
*		  Randomly generates x and y coordinates for each alien
*		  Adds the alien to the game object list
*/

void PlayField::PopulateAliens()
{
	GameRand::intRand xCoord(0, (int)m_bounds.x - 1); 
	GameRand::intRand yCoord(0, 10); 

	for (int k = 0; k < m_alienCount; k++)
	{
		Alien& a = *(new Alien);
		a.m_pos.x = (float)xCoord(GameRand::GetInstance()->rGen);
		a.m_pos.y = (float)yCoord(GameRand::GetInstance()->rGen);
		AddObject(&a);
	}
}

/*
* Brief : Populates the field with rocks
*		  Randomly generates x and y coordinates for each rock
*		  Adds the rock to the game object list
*/

void PlayField::PopulateRocks()
{
	GameRand::intRand xCoorRock(0, (int)m_bounds.x - 1);
	GameRand::intRand yCoordRock(10, 15);

	for (int k = 0; k < m_rockCount; k++)
	{
		Rock& a = *(new Rock);
		a.m_pos.x = (float)xCoorRock(GameRand::GetInstance()->rGen);
		a.m_pos.y = (float)yCoordRock(GameRand::GetInstance()->rGen);
		AddObject(&a);
	}
}

/*
* Brief : Populates the field with the player
*		  Sets the player's position
*		  Adds the player to the game object list
*/
void PlayField::PopulatePlayer()
{
	PlayerShip* p = new PlayerShip;
	p->m_pos = sf::Vector2f(40, 27);
	AddObject(p);
}