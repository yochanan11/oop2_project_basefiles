#include "Fish/FishEaten.h"
//-----------------------------------
FishEaten::FishEaten(const int Score):Fish(Score)
{
	
}
//-----------------------------------
FishEaten::~FishEaten()
{
}
//--------------------------------------
void FishEaten::move(sf::Time deltaTime)
{
    auto direction = getDirection();
    auto width = m_sprite.getGlobalBounds().width;
    sf::Vector2f vec(direction, 0);
    m_sprite.move(vec * SPEED_SFISH * deltaTime.asSeconds());

    // Check if fish goes off-screen and mark it for deletion
    if (direction == -1 && m_sprite.getPosition().x < -(width / 2))
        m_eaten = true;
    else if (direction == 1 && m_sprite.getPosition().x > WINDOW_WIDHT + width / 2)
        m_eaten = true;
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
void FishEaten::handleCollision(FishEaten& gameObject){}
//----------------------------------------
void FishEaten::handleCollision(ObstacleFish& gameObject){}
//----------------------------------------
void FishEaten::handleCollision(Obstacle& gameObject){}
//----------------------------------------
void FishEaten::handleCollision(GiftFreeze& gameObject){}
//----------------------------------------
void FishEaten::handleCollision(GiftSpeed& gameObject){}
//----------------------------------------

