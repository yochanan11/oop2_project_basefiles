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
private:
	//sf::Sprite m_sprite;
	virtual void draw(sf::RenderWindow&)  = 0;
	virtual void move(sf::Time deltaTime)  = 0;
};
