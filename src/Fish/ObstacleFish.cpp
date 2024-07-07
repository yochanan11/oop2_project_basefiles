#include "Fish/ObstacleFish.h"

ObstacleFish::ObstacleFish() : Fish(0)
{
	m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::OBSTACLE_F));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
		m_sprite.getGlobalBounds().height / 2.f);

}
//--------------------------------------------
ObstacleFish::~ObstacleFish(){}
//--------------------------------------------

void ObstacleFish::move(sf::Time deltaTime)
{
	auto direction = getDirection();
	auto width = m_sprite.getGlobalBounds().width;
	sf::Vector2f vec(direction, 0);
	m_sprite.move(vec * SPEED_OBSTACLE_F * deltaTime.asSeconds());

	// Check if fish goes off-screen and mark it for deletion
	if (direction == -1 && m_sprite.getPosition().x < -(width / 2))
		m_eaten = true;
	else if (direction == 1 && m_sprite.getPosition().x > WINDOW_WIDHT + width / 2)
		m_eaten = true;
}
//--------------------------------------------
void ObstacleFish::handleCollision(GameObject& gameObject) { gameObject.handleCollision(*this); }
//--------------------------------------------
void ObstacleFish::handleCollision(Player& gameObject)
{
	/*gameObject.setGameOver(false);*/
	gameObject.handleCollision(*this);
}
//--------------------------------------------
void ObstacleFish::handleCollision(FishEaten& gameObject){}
//--------------------------------------------
void ObstacleFish::handleCollision(ObstacleFish& gameObject){}
//--------------------------------------------
void ObstacleFish::handleCollision(Obstacle& gameObject){}
//--------------------------------------------
void ObstacleFish::handleCollision(GiftFreeze& gameObject){}
//--------------------------------------------
void ObstacleFish::handleCollision(GiftSpeed& gameObject){}
//--------------------------------------------