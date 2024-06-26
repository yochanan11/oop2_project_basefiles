#include "Player.h"
//--------------------------------
Player::Player(){ 
	m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::F_PLAYER));
    m_sprite.setOrigin(m_sprite.getTexture()->getSize().x / 2.f,
        m_sprite.getTexture()->getSize().y / 2.f);
}
//--------------------------------
Player::Player(sf::RenderWindow& window) {
    m_sprite.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
    Player();
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
    if(dirFromKey().x > 0)
    {
        if(m_scale)
        {
            m_sprite.setScale(1.f, 1.f);
            m_scale = false;
        }
        /*if (m_open)
            m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::F_PLAYER));
        else
            m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::F_PLAYER1));
        m_open = !m_open;*/
    }
    else if(dirFromKey().x < 0)
    {
        if(!m_scale)
        {
            m_sprite.setScale(-1.f, 1.f);
            m_scale = true;
        }
        
    }
}
//-------------------
void Player::setPosition(sf::RenderWindow& window)
{
    m_sprite.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
}
//-------------------