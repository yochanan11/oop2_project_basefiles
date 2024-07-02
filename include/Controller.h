#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Player.h"
#include "Level/ControllerLevel.h"

class Controller {
public:
    Controller();
    ~Controller();
    void run();
    void runMenu();
    void runGame();

private:
    Menu m_menu;
    ControllerLevel m_level;
    //sf::RenderWindow* m_window = nullptr;
    Player m_player;
    sf::Sprite m_bac;
};
