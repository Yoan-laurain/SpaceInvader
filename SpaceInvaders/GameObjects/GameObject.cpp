#include "GameObject.h"
#include "PlayField.h"

GameObject::GameObject() = default;
GameObject::~GameObject() = default;

void GameObject::Update(PlayField& world){}

bool GameObject::DecreaseHealth(float damage)
{
	return false;
}