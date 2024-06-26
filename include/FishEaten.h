#pragma once
#include "Fish.h"

class FishEaten:public Fish
{
public:
	FishEaten();
	~FishEaten();
	virtual void draw(sf::RenderWindow&) override;
	virtual void move(sf::Time, sf::RenderWindow&) override;
	virtual void setPosition(sf::RenderWindow&) override;

private:

};

