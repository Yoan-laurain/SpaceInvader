#include "PlayField.h"
#include "GameRand.h"
#include "../SpaceInvaders/GameObjects/Aliens/BetterAlien/BetterAlien.h"
#include "../SpaceInvaders/GameObjects/Aliens/SimpleAlien/Alien.h"
#include "../SpaceInvaders/GameObjects/Props/Rock.h"
#include <cassert>

PlayField::PlayField(const Vector2D& vector ) : Players(), m_bounds(vector), _InputMgr(nullptr)
{
	_InputMgr = new InputMgr();
	_InputMgr->Init();
	
	PopulateField();
}

PlayField::~PlayField()
{
	for (PlayerShip* p : Players)
	{
		if (nullptr != p)
			delete p;
	}
	Players.clear();
	
	if (_InputMgr)
	{
		delete _InputMgr;
		_InputMgr = nullptr;
	}

	for (auto it : m_gameObjects)
		if (nullptr != it)
			delete it;
	
	m_gameObjects.clear();

	for (auto it : m_gameObjectToAdd)
		if (nullptr != it)
			delete it;
	
	m_gameObjectToAdd.clear();
	
	for (auto it : m_gameObjectToRemove)
		if (nullptr != it)
			delete it;

	m_gameObjectToRemove.clear();
}

void PlayField::Start()
{
	for (auto it : Players) 
		if (nullptr != it)
			it->Start(); 
}

const std::vector<GameObject*>& PlayField::GameObjects()
{
	return m_gameObjects;
}

void PlayField::Update()
{
	_InputMgr->Update();
	
	for (auto it : m_gameObjectToRemove)
	{
		if (nullptr == it)
			continue;
		
		m_gameObjects.erase(std::find(m_gameObjects.begin(), m_gameObjects.end(), it));
		delete it;
	}
	
	for (auto it : m_gameObjectToAdd)
		if (nullptr != it)
			m_gameObjects.push_back(it);	

	m_gameObjectToAdd.clear();
	m_gameObjectToRemove.clear();	 

	if (m_alienCount == m_numberOfAliensBeforeBetterAlien)
		UpgradeAliens();

	for (auto it : m_gameObjects)
		if (nullptr != it)
			it->Update(*this);
}

void PlayField::AddNewPlayer(PlayerShip* player)
{
	if (nullptr == player) return;
	Players.push_back(player);

	_InputMgr->AddNewPlayer();
}

bool PlayField::BindAction(PlayerShip* player, InputAction inputAction, std::function<void(float)> func)
{
	if (nullptr == player) return false;

	int index = -1;
	for (int i = 0; i < Players.size(); ++i)
	{
		if (Players[i] == player)
		{
			index = i;
		}
	}

#if _DEBUG
	assert(index != -1);
#else
	if (index == -1)
	{
		return false;
	}
#endif

	_InputMgr->BindAction(index, inputAction, func);
	return true;
}

InputMgr* PlayField::GetInputMgr() const
{
	return _InputMgr;
}

GameObject* PlayField::GetPlayerObject()
{
	auto it = std::find_if(m_gameObjects.begin(), m_gameObjects.end(), [](GameObject* in) 
		{
			return (strcmp(in->m_objType, "PlayerShip") == 0);
		});

	if (it != m_gameObjects.end())
		return (*it);
	else
		return nullptr;
}

void PlayField::SpawnLaser(GameObject* newObj)
{
	if (nullptr == newObj) return;

	if (strcmp(newObj->m_objType, "AlienLaser") == 0)
		m_AlienLasers--;

	else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
		m_PlayerLasers--;

	AddObject(newObj);
}

void PlayField::DespawnLaser(GameObject* newObj)
{
	if (nullptr == newObj) return;
	
	if (strcmp(newObj->m_objType, "AlienLaser") == 0)
		m_AlienLasers++;

	else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
		m_PlayerLasers++;

	RemoveObject(newObj);
}

void PlayField::AddObject(GameObject* newObj)
{
	if (nullptr == newObj) return;
	
	m_gameObjectToAdd.push_back(newObj);
}

void PlayField::RemoveObject(GameObject* newObj)
{
	if (nullptr == newObj) return;

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
		if (nullptr != it)
			if (strcmp(it->m_objType, "Alien") == 0)
			{
				Alien* alien = static_cast<Alien*>(it);

				if (nullptr == alien) continue;
					
				BetterAlien* newAlien = new BetterAlien();

				if (nullptr == newAlien) continue;
				
				newAlien->m_pos = alien->m_pos;
				newAlien->SetDirection(alien->GetDirection());
			
				RemoveObject(it);
				AddObject(newAlien);
			}
}

/*
* Brief : Populates the field with aliens, rocks and the player
*/
void PlayField::PopulateField()
{
	GameRand* gameRandInstance = GameRand::GetInstance();

	if (nullptr == gameRandInstance) return;

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

	if (nullptr == p) return;
	
	p->m_pos = Vector2D((m_bounds.x / 2), (m_bounds.y - 2)); 
	AddObject(p);
	AddNewPlayer(p);
}