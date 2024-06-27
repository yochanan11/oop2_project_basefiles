#pragma once
#include "Fish.h"
#include "FishEaten.h"

class Player : virtual public Fish
{
public:
	Player();
	Player(sf::RenderWindow&);
	~Player();
	virtual void draw(sf::RenderWindow&) override;
	virtual void move(sf::Time, sf::RenderWindow&) override;
	virtual void setPosition(const int, const int) override;
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Player& gameObject) override;
	virtual void handleCollision(FishEaten & gameObject) override;
private:
	sf::Vector2f m_position_before;
	bool m_open = false,m_scale = false;
};

