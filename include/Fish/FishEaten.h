#pragma once
#include "Fish/Fish.h"
#include "Player.h"


class FishEaten:public Fish
{
public:
	FishEaten(const int);
	~FishEaten();
	virtual void move(sf::Time, sf::RenderWindow&,int) override;
	virtual void setPosition(const int, const int) override;
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Player& gameObject) override;
	virtual void handleCollision(FishEaten& gameObject) override;
	virtual void handleCollision(ObstacleFish& gameObject) override;

	

private:
};

