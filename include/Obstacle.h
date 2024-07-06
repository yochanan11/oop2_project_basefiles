#pragma once
#include "GameObject.h"
#include "Player.h"

class Obstacle :  public GameObject
{
public:
	Obstacle();
	~Obstacle();
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Player& gameObject) override;
	virtual void handleCollision(FishEaten& gameObject) override;
	virtual void handleCollision(ObstacleFish& gameObject) override;
	virtual void handleCollision(Obstacle& gameObject)override;
	virtual void handleCollision(GiftFreeze& gameObject)override;

private:

};

