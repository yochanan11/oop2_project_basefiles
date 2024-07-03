#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Macrose.h"

class Player;
class FishEaten;
class ObstacleFish;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	//virtual void setDirection(int) = 0;
	virtual void draw(sf::RenderWindow&);
	virtual void move(sf::Time, sf::RenderWindow&) = 0;
	virtual void handleCollision(GameObject& gameObject) = 0;
	virtual void handleCollision(Player& gameObject) = 0;
	virtual void handleCollision(FishEaten& gameObject) = 0;
	virtual void handleCollision(ObstacleFish& gameObject) = 0;

	void setPosition(float, float);
	void setDirection(int);
	int getDirection() const;
	bool checkCollision(const GameObject&) const;
	void setRotation();
	bool getIsEaten() const;
	sf::FloatRect getGlobalBounds() const;
	void setScale(float, float);

protected:
	sf::Sprite getSprite() const;
	sf::Sprite m_sprite;
	bool m_eaten = false;
private:
	int m_direction;
	//sf::Sprite m_sprite;
	
};
