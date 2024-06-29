#include "Fish/FishEaten.h"
//-----------------------------------
FishEaten::FishEaten(const int Score):Fish(Score)
{
	
	//m_sprite.scale(-1, 0);
}
//-----------------------------------
FishEaten::~FishEaten()
{
}
//--------------------------------------
void FishEaten::move(sf::Time deltaTime, sf::RenderWindow& window,int side)
{
	sf::Vector2f vec(side, 0.1f);
	m_sprite.move(vec *SPEED_SFISH * deltaTime.asSeconds());
	if (side == -1 && m_sprite.getPosition().x < 0)
		m_sprite.setPosition(window.getSize().x, m_sprite.getPosition().y);
	else if (m_sprite.getPosition().x > window.getSize().x)
		m_sprite.setPosition(0, m_sprite.getPosition().y);
	else if (m_sprite.getPosition().y > window.getSize().y)
		m_sprite.setPosition(m_sprite.getPosition().x, 0);
}
//--------------------------------------
void FishEaten::setPosition(const int window_x, const int window_y)
{
	m_sprite.setPosition(sf::Vector2f(window_x, window_y/4.f));
}
//--------------------------------------
void FishEaten::handleCollision(GameObject& gameObject){ gameObject.handleCollision(*this); }
//----------------------------------------
void FishEaten::handleCollision(Player& gameObject)
{
	if (!m_eaten)
		gameObject.handleCollision(*this);
	m_eaten = true;

}
//----------------------------------------
void FishEaten::handleCollision(FishEaten& gameObject)
{
}
//----------------------------------------
void FishEaten::handleCollision(ObstacleFish& gameObject)
{
}
//----------------------------------------

//--------------------------------------
