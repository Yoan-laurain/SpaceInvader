#include "PlayerInputAction.h"
#include "InputAction.h"

PlayerInputAction::PlayerInputAction(const unsigned playerIndex) : PlayerIndex(playerIndex)
{
	for (unsigned i = 0; i < static_cast<unsigned>(InputAction::Num); ++i)
	{
		auto action = static_cast<InputAction>(i);
		InputActionsInfo.emplace(action, InputActionInfo());
	}
}

void PlayerInputAction::SetInputAction(const InputAction action, const float value)
{
	InputActionInfo& info = InputActionsInfo.at(action);
	
	info.Value = value;
	for (auto callback : info.Callbacks)
	{
		callback(value);
	}
}

float PlayerInputAction::GetInputActionValue(const InputAction action) const
{
	return InputActionsInfo.at(action).Value;
}

bool PlayerInputAction::IsInputActionPressed(const InputAction action) const
{
	return InputActionsInfo.at(action).Value != 0.f;
}

bool PlayerInputAction::IsInputActionReleased(const InputAction action) const
{
	return InputActionsInfo.at(action).Value == 0.f;
}

void PlayerInputAction::BindAction(const InputAction inputAction, const std::function<void(float)> func)
{
	InputActionsInfo.at(inputAction).Callbacks.push_back(func);
}

PlayerInputAction::InputActionInfo::InputActionInfo() : Value(0.f)
{}
