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
	bool getGameOver()const;
	void setGameOver(bool);
	void setFirstScale();
	void setRotationAndScale();

private:
	sf::Vector2f dirFromKey();
	sf::Vector2f m_position_before;
	bool m_open = false,m_game_over = false;
	float m_initialScaleX; // scale הראשוני של התמונה
	float m_initialScaleY; // scale הראשוני של התמונה
	void handleSmallFishCollision(Fish& fish);
	void handleMediumFishCollision(Fish& fish);
	void isEaten(Fish&);

};
