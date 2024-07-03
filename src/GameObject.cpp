#include "GameObject.h"
//------------------------------------------
GameObject::GameObject(){}
//------------------------------------------
GameObject::~GameObject() {}
//------------------------------------------
void GameObject::draw(sf::RenderWindow& window) { window.draw(m_sprite); }
//------------------------------------------
sf::Sprite GameObject::getSprite() const { return m_sprite; }
//------------------------------------------
void GameObject::setRotation() { m_sprite.setScale(-1, 1); }
//------------------------------------------
bool GameObject::getIsEaten() const { return m_eaten; }
//------------------------------------------
bool GameObject::checkCollision(const GameObject& other) const
{
	if (&other == this) return false;
	return m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds());
}
//------------------------------------------
sf::FloatRect GameObject::getGlobalBounds() const
{
	return m_sprite.getGlobalBounds();
}
//------------------------------------------
void GameObject::setScale(float scaleX, float scaleY)
{
    m_sprite.setScale(scaleX, scaleY);
}
//------------------------------------------
void GameObject::setPosition(float x, float y) { m_sprite.setPosition(x, y); }
//------------------------------------------
void GameObject::setDirection(int direction) { m_direction = direction; }
//------------------------------------------
int GameObject::getDirection() const { return m_direction; }