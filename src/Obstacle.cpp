#include "Obstacle.h"

Obstacle::Obstacle()
{
	m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::OBSTACLE));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
		m_sprite.getGlobalBounds().height / 2.f);
}
//-------------------------------------------
Obstacle::~Obstacle()
{
}
//-------------------------------------------
void Obstacle::handleCollision(GameObject& gameObject){ gameObject.handleCollision(*this); }
//-------------------------------------------
void Obstacle::handleCollision(Player& gameObject) { gameObject.handleCollision(*this); }
//-------------------------------------------
void Obstacle::handleCollision(FishEaten& gameObject){}
//-------------------------------------------
void Obstacle::handleCollision(ObstacleFish& gameObject){}
//-------------------------------------------
void Obstacle::handleCollision(Obstacle& gameObject){}
//-------------------------------------------