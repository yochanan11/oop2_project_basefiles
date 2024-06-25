#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

class Command {
public:
    Command(sf::Texture&, const sf::Vector2f&);
    virtual void execute() = 0;
protected:
    sf::Sprite m_sprite_menu;
};

