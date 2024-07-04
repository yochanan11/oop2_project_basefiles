#include "Menu.h"
#include <iostream>

Menu::Menu() : m_bac(Resources::instance().getTexture(ObjIndex::MENU)) {
}
//------------------------------------
void Menu::add(std::string name, std::unique_ptr<Command> c) {
    m_options.emplace_back(m_option(name, std::move(c)));
}
//------------------------------------
void Menu::activate() {
    // פונקציה להפעלת התפריט (לא משמשת כרגע)
}
//------------------------------------
void Menu::drawMenu() {
    m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(989, 950), "Menu");
    while (m_window->isOpen()) {
        sf::Event event;
        while (m_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window->close();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                handleMouseClick(mousePos);
            }
        }
        m_window->clear();
        m_window->draw(m_bac);

        for (const auto& option : m_options) {
            option.second->draw(*m_window); // ציור כל כפתור
        }

        m_window->display();
    }
}
//------------------------------------
Menu::~Menu() {
}
//------------------------------------
void Menu::show() {
    for (unsigned i = 0; i < m_options.size(); i++)
        std::cout << i << " - " << m_options[i].first << "\n";
    std::cout << m_options.size() << "- Exit\n";
}
//------------------------------------
int Menu::getOptionFromUser() {
    std::cout << "your choice: ";
    int n;
    std::cin >> n;
    return n;
}
//------------------------------------
bool Menu::performAction(unsigned n) {
    if (n >= m_options.size())
        return false;
    m_options[n].second->execute();
    return true;
}
//------------------------------------
void Menu::handleMouseClick(const sf::Vector2f& mousePos) {
    for (unsigned i = 0; i < m_options.size(); i++) {
        if (m_options[i].second->isClicked(mousePos)) {
            m_window->close();
            m_options[i].second->execute();
        }
    }
}
