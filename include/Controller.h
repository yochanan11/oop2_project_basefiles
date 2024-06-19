#pragma once
#include "Fish.h"
#include <SFML/Graphics.hpp>
#include "Player.h"

class Controller
{
public:
	Controller();
	~Controller();
	void run();
private:
	sf::RenderWindow* m_window = nullptr;
	Player m_player;
	sf::Sprite m_bac;//,m_f;
	sf::Clock m_game_clock;
};

