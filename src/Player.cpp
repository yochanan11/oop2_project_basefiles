#include "Player.h"
#include <iostream>
#include <cmath>
#include <iostream>

//--------------------------------
Player::Player() : m_initialScaleX(0.5f), m_initialScaleY(0.5f), Fish(0)
{
    m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::F_PLAYER));
    m_sprite.setOrigin(m_sprite.getTexture()->getSize().x / 2.f,
        m_sprite.getTexture()->getSize().y / 2.f);
    m_sprite.setScale(m_initialScaleX, m_initialScaleY);
    m_sprite.setPosition(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2);

}
//--------------------------------
Player::~Player() {}
//--------------------------------
sf::Vector2f Player::dirFromKey()
{
        sf::Vector2f direction(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            direction.x += 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            direction.x -= 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            direction.y -= 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            direction.y += 1;

        // Normalize the direction vector to ensure consistent speed
        if (direction.x != 0.f || direction.y != 0.f)
        {
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
            direction /= length;
        }

        return direction;
}

//-------------------
void Player::handleCollision(GameObject& gameObject) { gameObject.handleCollision(*this); }
//-------------------
void Player::handleCollision(Player& gameObject) {}
//------------------
void Player::handleCollision(FishEaten& gameObject)
{
    m_score += gameObject.getScore();
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
void Player::move(sf::Time deltaTime)
{
    sf::Vector2f direction = dirFromKey();
    m_position_before = m_sprite.getPosition();
    m_sprite.move(direction * SPEED_PLAYER * deltaTime.asSeconds());

   
    if (direction.x > 0)
        setDirection(1);
    else if (direction.x < 0)
        setDirection(-1);
    else
        setDirection(0);

    if (m_sprite.getPosition().x > WINDOW_WIDHT - m_sprite.getGlobalBounds().width / 2)
        m_sprite.setPosition(WINDOW_WIDHT - m_sprite.getGlobalBounds().width / 2, m_sprite.getPosition().y);

    if (m_sprite.getPosition().x < m_sprite.getGlobalBounds().width / 2)
        m_sprite.setPosition(m_sprite.getGlobalBounds().width / 2, m_sprite.getPosition().y);

    if (m_sprite.getPosition().y > WINDOW_HEIGHT - m_sprite.getGlobalBounds().height / 2)
        m_sprite.setPosition(m_sprite.getPosition().x, WINDOW_HEIGHT - m_sprite.getGlobalBounds().height / 2);

    if (m_sprite.getPosition().y < m_sprite.getGlobalBounds().height / 2)
        m_sprite.setPosition(m_sprite.getPosition().x, m_sprite.getGlobalBounds().height / 2);
}

void Player::setRotationAndScale()
{
    float scale = m_initialScaleX + (m_score * 0.01f);

    if (getDirection() == 1)
        m_sprite.setScale(scale, scale);
    else if (getDirection() == -1)
        m_sprite.setScale(-scale, scale);

}
