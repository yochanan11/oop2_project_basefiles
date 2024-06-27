#pragma once
#include "Fish.h"
#include "Player.h"


class FishEaten:public Fish
{
public:
	FishEaten();
	~FishEaten();
	virtual void draw(sf::RenderWindow&) override;
	virtual void move(sf::Time, sf::RenderWindow&) override;
	virtual void setPosition(const int, const int) override;
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Player& gameObject) override;
	virtual void handleCollision(FishEaten& gameObject) override;
	

private:
	
};

