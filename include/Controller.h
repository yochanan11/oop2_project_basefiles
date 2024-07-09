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
    Player& getPlayer();

private:
    Menu m_menu;
    ControllerLevel m_level;
    Player m_player;
};
