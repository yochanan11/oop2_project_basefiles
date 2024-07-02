#include "Player.h"
#include <iostream>
//--------------------------------
Player::Player():m_initialScaleX(0.5f), m_initialScaleY(0.5f),Fish(0)
{
	m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::F_PLAYER));
    m_sprite.setOrigin(m_sprite.getTexture()->getSize().x / 2.f,
        m_sprite.getTexture()->getSize().y / 2.f);
    m_sprite.setScale(m_initialScaleX, m_initialScaleY);
}
//--------------------------------
Player::Player(sf::RenderWindow& window) :Fish(0) {
    m_sprite.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
    Player();
}
//--------------------------------
Player::~Player(){}
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
void Player::handleCollision(GameObject& gameObject) { gameObject.handleCollision(*this); }
//-------------------
void Player::handleCollision(Player& gameObject)
{
    
}
//------------------
void Player::handleCollision(FishEaten& gameObject)
{
   m_score+= gameObject.getScore();
   Resources::instance().playSound(SoundIndex::EAT);

}
//------------------------------------
void Player::handleCollision(ObstacleFish& gameObject)
{
    Resources::instance().playSound(SoundIndex::GAME_OVER);
    m_game_over = true;
}
//------------------------------------
bool Player::getGameOver() const { return m_game_over; }
//-------------------
void Player::move(sf::Time deltaTime,sf::RenderWindow& window,int side)
{
    if (m_score > 10)
    {
        m_initialScaleX = m_initialScaleY = 1.f;
        //m_sprite.setScale(m_initialScaleX, m_initialScaleY);
    }
    m_position_before = m_sprite.getPosition();
    m_sprite.move(dirFromKey() * SPEED_PLAYER * deltaTime.asSeconds());
    if (m_sprite.getPosition().x > window.getSize().x-150 ||
        m_sprite.getPosition().x < 150 ||
        m_sprite.getPosition().y > window.getSize().y-100 ||
        m_sprite.getPosition().y < 100)
        m_sprite.setPosition(m_position_before);
    if(dirFromKey().x > 0)
    {
        if(m_scale)
        {
            m_sprite.setScale(m_initialScaleX, m_initialScaleY);
            m_scale = false;
        }
    }
    else if(dirFromKey().x < 0)
    {
        if(!m_scale)
        {
            m_sprite.setScale(-m_initialScaleX, m_initialScaleY);
            m_scale = true;
        }
        
    }
    
}
//-------------------
void Player::setPosition(const int window_x, const int window_y)
{
    m_sprite.setPosition(window_x / 2.f, window_y / 2.f);
}
//-------------------