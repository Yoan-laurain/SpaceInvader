#include "PlayerField.h"
#include "RndInput.h"

PlayField::PlayField(Vector2D iBounds) : m_bounds(iBounds)
{
	m_controllerInput = new RndInput;
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
		m_gameObjects.erase(std::remove(m_gameObjects.begin(), m_gameObjects.end(), it), m_gameObjects.end());
	}

	m_gameObjectToAdd.clear();
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

	m_gameObjectToRemove.push_back(*it);
}