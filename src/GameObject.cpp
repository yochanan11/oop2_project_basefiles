#include "GameObject.h"
//------------------------------------------
GameObject::GameObject(){}
//------------------------------------------
GameObject::~GameObject() {}
//------------------------------------------
sf::Sprite GameObject::getSprite() { return m_sprite; }
//------------------------------------------
bool GameObject::getIsEaten() { return m_eaten; }
//------------------------------------------
bool GameObject::checkCollision(const GameObject& other) const
{
	if (&other == this) return false;
	return m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds());
}