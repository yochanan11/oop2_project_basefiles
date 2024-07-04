#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Player.h"
#include "Fish/Fish.h"
#include "Fish/FishEaten.h"
#include "Fish/SmallFish.h"
#include"Fish/MediumFish.h"
#include"Fish/ObstacleFish.h"



class Level {
public:
    Level();
    Level(Player&,sf::Texture&);
    virtual void run() = 0;

protected:
    sf::Sprite m_bec_level;
    sf::RenderWindow* m_window = nullptr;
    Player* m_player = nullptr;
    std::vector<std::unique_ptr<GameObject>> m_fish_eaten;
    sf::Clock m_game_clock;
    sf::Text m_text_score, m_gameOverText;
    sf::RectangleShape m_game_over_rec;
        
};

