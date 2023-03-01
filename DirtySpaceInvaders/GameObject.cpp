#include "GameObject.h"

bool GameObject::IntCmp(const sf::Vector2f& vec)
{
	return int(m_pos.x) == int(vec.x) && int(m_pos.y) == int(vec.y);
}

void GameObject::Update(PlayField& world){}

bool GameObject::DecreaseHealth()
{
	return false;
}