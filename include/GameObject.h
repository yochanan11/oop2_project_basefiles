#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Macrose.h"

class Player;
class FishEaten;
class ObstacleFish;
class Obstacle;
class GiftFreeze;
class GiftSpeed;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void draw(sf::RenderWindow&);
	virtual void handleCollision(GameObject& gameObject) = 0;
	virtual void handleCollision(Player& gameObject) = 0;
	virtual void handleCollision(FishEaten& gameObject) = 0;
	virtual void handleCollision(ObstacleFish& gameObject) = 0;
	virtual void handleCollision(Obstacle& gameObject) = 0;
	virtual void handleCollision(GiftFreeze& gameObject) = 0;
	virtual void handleCollision(GiftSpeed& gameObject) =0;

	void setPosition(float, float);
	void setDirection(int);
	int getDirection() const;
	bool checkCollision(const GameObject&) const;
	void setRotation();
	
	sf::FloatRect getGlobalBounds() const;
	void setScale(float, float);
	

protected:
	sf::Sprite getSprite() const;
	sf::Sprite m_sprite;
	
private:
	int m_direction;	
};
