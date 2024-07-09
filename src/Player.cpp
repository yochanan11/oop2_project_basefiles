#include "Player.h"
#include <iostream>
#include <cmath>
#include <Fish/SmallFish.h>
#include <Fish/MediumFish.h>

//--------------------------------
Player::Player() : m_initialScaleX(0.5f), Fish(0)
{
    m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::F_PLAYER));
    m_sprite.setOrigin(m_sprite.getTexture()->getSize().x / 2.f,
        m_sprite.getTexture()->getSize().y / 2.f);
    m_sprite.setScale(m_initialScaleX, m_initialScaleX);
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
    // Determine the type of FishEaten and handle accordingly
    if (dynamic_cast<SmallFish*>(&gameObject)) {
        handleSmallFishCollision(gameObject);
    }
    else if (dynamic_cast<MediumFish*>(&gameObject)) {
        handleMediumFishCollision(gameObject);
    }
    else {
        // Other fish collision handling
    }
}
//------------------------------------
void Player::handleCollision(ObstacleFish& gameObject)
{
    if (!m_freezeActive)
        m_game_over = true;
}
//------------------------------------
void Player::handleCollision(Obstacle& gameObject) {
    if (!m_freezeActive)
    {
        m_sprite.setPosition(m_position_before.x, m_position_before.y - 50);
        if (m_score - 5 <= 0)
            m_game_over = true;
        else
            m_score -= 5;
    }
}
//-------------------------------------
void Player::handleCollision(GiftFreeze& gameObject)
{
    if (!m_freezeActive)
    {
        m_freezeActive = true;
        m_sprite.setColor(sf::Color(255, 255, 255, 128));
        m_freezeClock.restart();
        Resources::instance().playSound(SoundIndex::GIFT);
    }
}
//-------------------------------------
void Player::handleCollision(GiftSpeed& gameObject)
{
    if (!m_speedActive)
    {
        m_speedActive = true;
        m_sprite.setColor(sf::Color(200, 200, 200, 200));
        m_speedClock.restart();
        Resources::instance().playSound(SoundIndex::GIFT);
    }
}
//------------------------------------
bool Player::getGameOver() const { return m_game_over; }
//------------------------------------
void Player::setGameOver(bool GameOver) { m_game_over = GameOver; }
//------------------------------------
void Player::setFirstScale()
{
    m_sprite.setScale(0.5f, 0.5f);
    m_initialScaleX = 0.5f;
}
//------------------------------------
void Player::move(sf::Time deltaTime)
{
    if (m_freezeActive && m_freezeClock.getElapsedTime().asSeconds() >= 7.0f)
        resetEffect(m_freezeActive);

    if (m_speedActive && m_speedClock.getElapsedTime().asSeconds() >= 7.0f)
        resetEffect(m_speedActive);

    sf::Vector2f direction = dirFromKey();
    m_position_before = m_sprite.getPosition();

    float speedMultiplier = m_speedActive ? 2.0f : 1.0f;
    m_sprite.move(direction * SPEED_PLAYER * speedMultiplier * deltaTime.asSeconds());

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
//------------------------------------
void Player::setRotationAndScale()
{
    float scale = m_initialScaleX + (m_score * 0.01f);

    if (getDirection() == 1)
        m_sprite.setScale(scale, scale);
    else if (getDirection() == -1)
        m_sprite.setScale(-scale, scale);

}
//------------------------------------
void Player::setName(std::string name) { m_name = name; }
//------------------------------------
std::string Player::getName() const { return m_name; }
//------------------------------------
void Player::handleSmallFishCollision(Fish& fish) {
    // Logic for handling collision with small fish
    isEaten(fish);
}
//------------------------------------
void Player::handleMediumFishCollision(Fish& fish) {
    // Logic for handling collision with medium fish
    if (!m_freezeActive && m_score < 16)
        setGameOver(true);
    else
        isEaten(fish);
}
//------------------------------------
void Player::isEaten(Fish& fish)
{
    fish.setIsEaten(true);
    m_score += fish.getScore();
    Resources::instance().playSound(SoundIndex::EAT);
}
//-----------------------------------
void Player::resetEffect(bool& gift)
{
    gift = false;
    m_sprite.setColor(sf::Color(255, 255, 255, 255)); // Set alpha to 255 for full opacity
}

