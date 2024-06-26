#include "Level/Level1.h"

Level1::Level1(){}

Level1::Level1(Player& player) :Level(player,
	Resources::instance().getTexture(ObjIndex::BACKGROUND))
{
}
//---------------------------------
Level1::~Level1()
{
}
//---------------------------------
void Level1::run()
{
    sf::RenderWindow window(sf::VideoMode(1400, 900), "Fish Eat Fishes");
    m_window = &window;
	FishEaten fish;
    fish.setPosition(*m_window);
	m_fish_eaten.push_back(fish);
    m_player->setPosition(*m_window);
    while (m_window->isOpen())
    {
        const auto deltaTime = m_game_clock.restart();
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }
        m_player->move(deltaTime);
        for (auto& it : m_fish_eaten)
            it.move(deltaTime);
        m_window->clear();
        m_window->draw(m_bec_level);
        for (auto it: m_fish_eaten)
            it.draw(*m_window);
        //m_window->draw(m_f);
        m_player->draw(*m_window);
        m_window->display();
    }
}
