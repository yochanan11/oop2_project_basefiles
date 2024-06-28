#include "Fish/FishEaten.h"
//-----------------------------------
FishEaten::FishEaten(const int rand):Fish(2)
{
	m_sprite.setTexture(getRandTex(rand));
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
void FishEaten::move(sf::Time deltaTime, sf::RenderWindow& window,int side)
{
	sf::Vector2f vec(side, 0);
	m_sprite.move(vec *SPEED * deltaTime.asSeconds());
	if (side == -1 && m_sprite.getPosition().x < 0)
		m_sprite.setPosition(window.getSize().x, m_sprite.getPosition().y);
	else if (m_sprite.getPosition().x > window.getSize().x)
		m_sprite.setPosition(0, m_sprite.getPosition().y);
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
sf::Texture& FishEaten::getRandTex(const int rand)
{
	switch (rand)
	{
	case 1:
		return Resources::instance().getTexture(ObjIndex::FISH_E1);
		break;
	case 2:
		return Resources::instance().getTexture(ObjIndex::FISH_E2);
		break;
	case 3:
		return Resources::instance().getTexture(ObjIndex::FISH_E3);
		break;
	case 4:
		return Resources::instance().getTexture(ObjIndex::FISH_E4);
		break;
	default:
		break;
	}
}
//--------------------------------------
