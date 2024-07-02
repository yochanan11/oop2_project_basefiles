#include "Command.h"

Command::Command(sf::Texture& tex, const sf::Vector2f& position)
    : m_sprite_menu(tex)
{
    m_sprite_menu.setOrigin(m_sprite_menu.getGlobalBounds().width / 2, m_sprite_menu.getGlobalBounds().height / 2);
    m_sprite_menu.setPosition(position);
}
//------------------------------------
Command::~Command()
{
}
//------------------------------------
void Command::draw(sf::RenderWindow& window) {
    window.draw(m_sprite_menu);
}
//------------------------------------
bool Command::isClicked(const sf::Vector2f& mousePos) const {
    return m_sprite_menu.getGlobalBounds().contains(mousePos);
}
