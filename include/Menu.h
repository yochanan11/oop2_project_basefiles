#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <Command.h>

class Menu {
public:
    Menu();
    void add(std::string name, std::unique_ptr<Command> c);
    void activate();
    void drawMenu();
    ~Menu();

private:
    sf::Sprite m_bac;
    sf::RenderWindow* m_window = nullptr;
    typedef std::pair<std::string, std::unique_ptr<Command>> m_option;
    std::vector<m_option> m_options;
    //---------------------------
    void show();
    int getOptionFromUser();
    bool performAction(unsigned n);
};