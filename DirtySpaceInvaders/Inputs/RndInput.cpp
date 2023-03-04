#include "RndInput.h"
#include "GameRand.h"

bool RndInput::Left()
{
	GameRand::floatRand keyRate(0, 1); 
	return (keyRate(GameRand::GetInstance()->rGen) < 0.3f);
}

bool RndInput::Right()
{
	GameRand::floatRand keyRate(0, 1);
	return (keyRate(GameRand::GetInstance()->rGen) < 0.4f);
}

bool RndInput::Fire()
{
	GameRand::floatRand keyRate(0, 1);
	return (keyRate(GameRand::GetInstance()->rGen) < 0.5f);
}
