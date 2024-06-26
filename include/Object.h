#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Macrose.h";

class Object
{
public:
	Object();
	virtual ~Object();
protected:
	sf::Sprite getSprite();
	sf::Sprite m_sprite;
	virtual void setPosition(sf::RenderWindow&) = 0;
	virtual void draw(sf::RenderWindow&) = 0;
	virtual void move(sf::Time, sf::RenderWindow&) = 0;
private:
	//sf::Sprite m_sprite;
	
};
