#include "FishEaten.h"
//-----------------------------------
FishEaten::FishEaten()
{
	m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::FISH_E1));
	m_sprite.setOrigin(m_sprite.getTexture()->getSize().x / 2.f,
		m_sprite.getTexture()->getSize().y / 2.f);
	//m_sprite.scale(-1, 0);
}
//-----------------------------------
FishEaten::~FishEaten()
{
}
//-----------------------------------
void FishEaten::draw(sf::RenderWindow& window) { window.draw(m_sprite); }
//--------------------------------------
void FishEaten::move(sf::Time deltaTime, sf::RenderWindow& window)
{
	sf::Vector2f vec(-1, 0);
	m_sprite.move(vec *SPEED * deltaTime.asSeconds());
	if (m_sprite.getPosition().x < 0)
		m_sprite.setPosition(window.getSize().x, m_sprite.getPosition().y);
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
//--------------------------------------
