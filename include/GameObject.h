#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Macrose.h"

class Player;
class FishEaten;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void setPosition(const int,const int) = 0;
	virtual void draw(sf::RenderWindow&) = 0;
	virtual void move(sf::Time, sf::RenderWindow&) = 0;
	virtual void handleCollision(GameObject& gameObject) = 0;
	virtual void handleCollision(Player& gameObject) = 0;
	virtual void handleCollision(FishEaten& gameObject) = 0;
	bool checkCollision(const GameObject&) const;
	bool getIsEaten();
protected:
	sf::Sprite getSprite();
	sf::Sprite m_sprite;
	bool m_eaten = false;
private:
	//sf::Sprite m_sprite;
	
};
