#pragma once
#include <random>

class GameRand
{
	public : 

		static GameRand* GetInstance();

		std::default_random_engine rGen;
		typedef std::uniform_int_distribution<int> intRand;
		typedef std::uniform_real_distribution<float> floatRand;

	protected :
		static GameRand* m_instance;
};