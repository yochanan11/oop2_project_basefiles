#include "Player.h"
//--------------------------------
Player::Player(){ 
	m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::F_PLAYER));
	m_sprite.setPosition(sf::Vector2f(100.f, 100.f));
}
//--------------------------------
Player::~Player(){}
//--------------------------------
void Player::draw(sf::RenderWindow& m_window){
	m_window.draw(m_sprite);
}
//--------------------------------
namespace
{
    sf::Vector2f dirFromKey()
    {
        static const
            std::initializer_list<std::pair<sf::Keyboard::Key, sf::Vector2f>>
            keyToVectorMapping =
        {
            { sf::Keyboard::Right, { 1, 0 } },
            { sf::Keyboard::Left , { -1, 0 } },
            { sf::Keyboard::Up   , { 0, -1 } },
            { sf::Keyboard::Down , { 0, 1 } },
        };
        for (const auto& pair : keyToVectorMapping)
            if (sf::Keyboard::isKeyPressed(pair.first)) return pair.second;
        return { 0, 0 };
    }
}
//-------------------
void Player::move(sf::Time deltaTime)
{
    m_position_before = m_sprite.getPosition();
    m_sprite.move(dirFromKey() * SPEED * deltaTime.asSeconds());
}
//-------------------