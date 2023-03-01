#pragma once
#include <vector>
#include "GameObject.h"
#include "PlayerShip.h"
#include <InputMgr.h>

class PlayField
{
	public:
		InputMgr* _InputMgr;
		sf::Vector2f m_bounds;

		// Number of available active laser slots for aliens and player
		int m_AlienLasers = 10;
		int m_PlayerLasers = 40;

		int m_alienCount = 5;
		int m_rockCount = 5;

		int m_numberOfAliensBeforeBetterAlien = 3;

		PlayField(sf::Vector2f iBounds);
		~PlayField();

		void Start();
		
		const std::vector<GameObject*>& GameObjects();

		void Update();
		void AddNewPlayer(PlayerShip* player);

		bool BindAction(PlayerShip* player, InputAction inputAction, std::function<void(float)> func);
		InputMgr* GetInputMgr() const;

		GameObject* GetPlayerObject();

		void SpawnLaser(GameObject* newObj);

		void DespawnLaser(GameObject* newObj);

		void AddObject(GameObject* newObj);

		void RemoveObject(GameObject* newObj);
				
		void UpgradeAliens();

		void PopulateField();
		
		void PopulateAliens();
		
		void PopulateRocks();
		
		void PopulatePlayer();

	private:
		std::vector<GameObject*> m_gameObjects;
		std::vector<GameObject*> m_gameObjectToAdd;
		std::vector<GameObject*> m_gameObjectToRemove;

	protected :
		std::vector<PlayerShip*> Players;
	
};

PlayField* GetGame();