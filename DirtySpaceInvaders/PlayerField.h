#pragma once
#include <vector>
#include "Vector2D.h"
#include "GameObject.h"
#include "Input.h"

class PlayField
{
	public:
		Input* m_controllerInput;
		Vector2D m_bounds;

		// Number of available active laser slots for aliens and player
		int m_AlienLasers = 10;
		int m_PlayerLasers = 4;

		PlayField(Vector2D iBounds);
		const std::vector<GameObject*>& GameObjects();

		void Update();

		GameObject* GetPlayerObject();

		void SpawnLaser(GameObject* newObj);

		void DespawnLaser(GameObject* newObj);

		void AddObject(GameObject* newObj);

		void RemoveObject(GameObject* newObj);

	private:
		std::vector<GameObject*> m_gameObjects;
		std::vector<GameObject*> m_gameObjectToAdd;
};