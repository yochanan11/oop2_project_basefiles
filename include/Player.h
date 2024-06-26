#pragma once
#include "Fish.h"

class Player : virtual public Fish
{
public:
	Player();
	Player(sf::RenderWindow&);
	~Player();
	virtual void draw(sf::RenderWindow&) override;
	virtual void move(sf::Time, sf::RenderWindow&) override;
	virtual void setPosition(sf::RenderWindow&) override;

private:
	sf::Vector2f m_position_before;
	bool m_open = false,m_scale = false;
};

