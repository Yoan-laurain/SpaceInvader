#include "InputMgr.h"
#include "InputAction.h"
#include <SFML/Window/Keyboard.hpp>
#include <assert.h>

bool InputMgr::Init()
{
	return true;
}

bool InputMgr::Update()
{
	for (const auto& [fst, snd] : InputBinds)
	{
		const sf::Keyboard::Key& key = fst;
		const InputBindInfo& bindInfo = snd;

		if (sf::Keyboard::isKeyPressed(key))
		{
			SetPlayerActionState(bindInfo.PlayerIndex, bindInfo.Action, 1.f);
		}
		else
		{
			SetPlayerActionState(bindInfo.PlayerIndex, bindInfo.Action, 0.f);
		}
	}

	return true;
}

bool InputMgr::Reset()
{
	return false;
}

void InputMgr::AddNewPlayer()
{
	const unsigned index = PlayersInputAction.size();
	PlayersInputAction.push_back(PlayerInputAction(index));

	if (index == 0)
	{
#define INIT_DEFAULT_BIND(key, bind) InputBinds.insert(std::make_pair(key, bind));
#include "DefaultKeyBind.h"
#undef INIT_DEFAULT_BIND
	}
}

void InputMgr::BindAction(const int playerIndex, const InputAction inputAction, const std::function<void(float)> func)
{
	PlayersInputAction[playerIndex].BindAction(inputAction, func);
}

void InputMgr::SetPlayerActionState(const unsigned playerIndex,const InputAction action, const float value)
{
#if _DEBUG
	assert(playerIndex < PlayersInputAction.size());
#endif

	PlayersInputAction[playerIndex].SetInputAction(action, value);
}

InputMgr::InputBindInfo::InputBindInfo(const unsigned playerIndex,const InputAction action) : PlayerIndex(playerIndex), Action(action)
{}
