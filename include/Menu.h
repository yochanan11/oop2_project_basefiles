#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Command.h"
#include "Resources.h"

class Menu {
public:
    Menu();
    void add(std::string name, std::unique_ptr<Command> c);
    void activate();
    void drawMenu();
    ~Menu();

private:
    sf::Sprite m_bac;
    std::unique_ptr<sf::RenderWindow> m_window;
    typedef std::pair<std::string, std::unique_ptr<Command>> m_option;
    std::vector<m_option> m_options;

    void show();
    int getOptionFromUser();
    bool performAction(unsigned n);
    void handleMouseClick(const sf::Vector2f& mousePos);
};
