#pragma once
#include "Gift.h"
#include "Player.h"

class GiftFreeze : public Gift
{
public:
    GiftFreeze();
    ~GiftFreeze();
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Player& gameObject) override;
	virtual void handleCollision(FishEaten& gameObject) override;
	virtual void handleCollision(ObstacleFish& gameObject) override;
	virtual void handleCollision(Obstacle& gameObject) override;
	//virtual void handleCollision(GiftFreeze& gameObject) override;

private:
    bool m_freezeActive = false; // Changed name to avoid conflict
    sf::Clock m_freezeClock; // Changed name to avoid conflict
};
