#pragma once
#include "Fish/Fish.h"
#include "Fish/FishEaten.h"

class Player : virtual public Fish
{
public:
	Player();
	~Player();
	virtual void move(sf::Time) override;
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Player& gameObject) override;
	virtual void handleCollision(FishEaten & gameObject) override;
	virtual void handleCollision(ObstacleFish& gameObject) override;
	virtual void handleCollision(Obstacle& gameObject)override;
	virtual void handleCollision(GiftFreeze& gameObject)override;
	virtual void handleCollision(GiftSpeed& gameObject)override;

	bool getGameOver()const;
	void setGameOver(bool);
	void setFirstScale();
	void setRotationAndScale();
	void setName(std::string);
	std::string getName()const;

private:
	std::string m_name;
	sf::Vector2f dirFromKey();
	sf::Vector2f m_position_before;
	sf::Clock m_speedClock , m_freezeClock;
	bool m_open = false,m_game_over = false, m_speedActive = false, m_freezeActive = false;
	float m_initialScaleX; 

	void handleSmallFishCollision(Fish& fish);
	void handleMediumFishCollision(Fish& fish);
	void isEaten(Fish&);
	void resetEffect(bool&);

};
