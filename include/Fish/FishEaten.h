#pragma once
#include "Fish/Fish.h"
#include "Player.h"


class FishEaten:public Fish
{
public:
	FishEaten(const int);
	~FishEaten();
	virtual void move(sf::Time) override;
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Player& gameObject) override;
	virtual void handleCollision(FishEaten& gameObject) override;
	virtual void handleCollision(ObstacleFish& gameObject) override;
	virtual void handleCollision(Obstacle& gameObject)override;
	virtual void handleCollision(GiftFreeze& gameObject)override;
	virtual void handleCollision(GiftSpeed& gameObject) override;

private:
};

