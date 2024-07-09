#pragma once
#include <SFML/Graphics.hpp>

class Command {
public:
    Command(sf::Texture&, const sf::Vector2f&);
    virtual ~Command();
    virtual void execute() = 0;
    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Vector2f& mousePos) const; 
protected:
    sf::Sprite m_sprite_menu;
};
