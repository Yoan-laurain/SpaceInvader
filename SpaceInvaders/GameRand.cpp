#include "GameRand.h"

GameRand* GameRand::m_instance = nullptr;

GameRand* GameRand::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new GameRand();
	}
	return m_instance;
}
