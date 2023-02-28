#pragma once
#include <vector>
#include "GameObject.h"
#include "Input.h"

class PlayField
{
	public:
		Input* m_controllerInput;
		sf::Vector2f m_bounds;

		// Number of available active laser slots for aliens and player
		int m_AlienLasers = 10;
		int m_PlayerLasers = 40;

		int m_alienCount = 5;
		int m_rockCount = 5;

		PlayField(sf::Vector2f iBounds);
		const std::vector<GameObject*>& GameObjects();

		void Update();

		GameObject* GetPlayerObject();

		void SpawnLaser(GameObject* newObj);

		void DespawnLaser(GameObject* newObj);

		void AddObject(GameObject* newObj);

		void RemoveObject(GameObject* newObj);
		
		void UpgradeAliens();

	private:
		std::vector<GameObject*> m_gameObjects;
		std::vector<GameObject*> m_gameObjectToAdd;
		std::vector<GameObject*> m_gameObjectToRemove;
};