#include "Fish/ObstacleFish.h"

ObstacleFish::ObstacleFish() : Fish(0)
{
	m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::OBSTACLE_F));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
		m_sprite.getGlobalBounds().height / 2.f);

}
//--------------------------------------------
ObstacleFish::~ObstacleFish()
{
}
//--------------------------------------------
void ObstacleFish::move(sf::Time deltaTime, sf::RenderWindow& window)
{
	auto direction = getDirection();
	sf::Vector2f vec(direction, 0.1f);
	m_sprite.move(vec * SPEED_OBSTACLE_F * deltaTime.asSeconds());
	if (direction == -1 && m_sprite.getPosition().x < 0)
		m_sprite.setPosition(window.getSize().x, m_sprite.getPosition().y);
	else if (m_sprite.getPosition().x > window.getSize().x)
		m_sprite.setPosition(0, m_sprite.getPosition().y);
	else if (m_sprite.getPosition().y > window.getSize().y)
		m_sprite.setPosition(m_sprite.getPosition().x, 0);
}
//--------------------------------------------
void ObstacleFish::handleCollision(GameObject& gameObject) { gameObject.handleCollision(*this); }
//--------------------------------------------
void ObstacleFish::handleCollision(Player& gameObject)
{
	gameObject.handleCollision(*this);
}
//--------------------------------------------
void ObstacleFish::handleCollision(FishEaten& gameObject)
{
}
//--------------------------------------------
void ObstacleFish::handleCollision(ObstacleFish& gameObject)
{
}
//--------------------------------------------