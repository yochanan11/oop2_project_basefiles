#pragma once
#include "Fish/Fish.h"
#include "Fish/FishEaten.h"

class Player : virtual public Fish
{
public:
	Player();
	Player(sf::RenderWindow&);
	~Player();
	virtual void move(sf::Time, sf::RenderWindow&,int) override;
	virtual void setPosition(const int, const int) override;
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Player& gameObject) override;
	virtual void handleCollision(FishEaten & gameObject) override;
	virtual void handleCollision(ObstacleFish& gameObject) override;
	bool getGameOver()const;

private:
	sf::Vector2f m_position_before;
	bool m_open = false,m_scale = false,m_game_over = false;
};

