#include "Menu/Help.h"
#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Help::Help()
    : Command(Resources::instance().getTexture(ObjIndex::HELP_B), sf::Vector2f(440, 830))
{
    m_sprite_menu.setScale(0.35f, 0.35f);
}
//-------------------------------------
Help::~Help() {}
//-------------------------------------
void Help::execute() {
    // Create the new window
    sf::RenderWindow helpWindow(sf::VideoMode(900, 675), "Help");

    // Load the texture for the help image
    sf::Texture helpTexture = Resources::instance().getTexture(ObjIndex::HELP);
    sf::Sprite helpSprite;
    helpSprite.setTexture(helpTexture);
    helpSprite.setScale(float(helpWindow.getSize().x) / helpTexture.getSize().x, float(helpWindow.getSize().y) / helpTexture.getSize().y);

    // Event loop for the new window
    while (helpWindow.isOpen()) {
        sf::Event event;
        while (helpWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                helpWindow.close();
            }
        }

        // Clear the window
        helpWindow.clear();

        // Draw the help image
        helpWindow.draw(helpSprite);

        // Display the content drawn
        helpWindow.display();
    }
}
