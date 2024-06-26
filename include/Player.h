#pragma once
#include "Fish.h"

class Player : virtual public Fish
{
public:
	Player();
	~Player();
	virtual void draw(sf::RenderWindow&) override;
	virtual void move(sf::Time deltaTime) override;

private:
	sf::Vector2f m_position_before;
	bool m_open = false,m_scale = false;
};

