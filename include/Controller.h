#pragma once
#include "Fish/Fish.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Menu.h"
#include "Level/ControllerLevel.h"

class Controller
{
public:
	Controller();
	~Controller();
	void run();
private:
	Menu m_menu;
	ControllerLevel m_level;
	sf::RenderWindow* m_window = nullptr;
	Player m_player;
	sf::Sprite m_bac;//,m_f;
	
};

