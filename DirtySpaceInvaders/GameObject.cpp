#include "GameObject.h"
#include "PlayerShip.h"
#include "Alien.h"

bool GameObject::IntCmp(const sf::Vector2f& vec)
{
	return int(pos.x) == int(vec.x) && int(pos.y) == int(vec.y);
}

void GameObject::Update(PlayField& world){}

bool GameObject::DecreaseHealth()
{
	return false;
}