#include "FishEaten.h"
//-----------------------------------
FishEaten::FishEaten()
{
	m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::FISH_E1));
	m_sprite.setOrigin(m_sprite.getTexture()->getSize().x / 2.f,
		m_sprite.getTexture()->getSize().y / 2.f);
}
//-----------------------------------
FishEaten::~FishEaten()
{
}
//-----------------------------------
void FishEaten::draw(sf::RenderWindow& window) { window.draw(m_sprite); }
//--------------------------------------
void FishEaten::move(sf::Time deltaTime)
{
	sf::Vector2f vec(1, 0);
	m_sprite.move(vec *SPEED * deltaTime.asSeconds());
}
//--------------------------------------
void FishEaten::setPosition(sf::RenderWindow& window) 
{
	m_sprite.setPosition(sf::Vector2f(window.getSize().x / 4.f, window.getSize().y / 4.f));
}
