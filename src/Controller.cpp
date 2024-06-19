#include "Controller.h"
//--------------------------
Controller::Controller()
{
    m_bac.setTexture(Resources::instance().getTexture(ObjIndex::BACKGROUND));
}
//--------------------------
Controller::~Controller()
{
}
//--------------------------
void Controller::run()
{
	sf::RenderWindow window(sf::VideoMode(1400, 900), "Fish Eat Fishes");
	m_window = &window;
    while (m_window->isOpen())
    {
        const auto deltaTime = m_game_clock.restart();
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }
        m_player.move(deltaTime);
        m_window->clear();
        m_window->draw(m_bac);
        //m_window->draw(m_f);
        m_player.draw(window);
        m_window->display();
    }
}

