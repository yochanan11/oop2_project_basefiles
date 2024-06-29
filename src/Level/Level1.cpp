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
    sf::RenderWindow window(sf::VideoMode(1400, 900), "Fish Eats Fish");
    m_window = &window;
    m_text_score.setPosition(sf::Vector2f(50.f, 50.f));
    std::srand(std::time(0));
    int random_number;
    for (size_t i = 1; i < 9; i++)
    {
        random_number = std::rand() % 4 + 1;
        m_fish_eaten.push_back(std::make_unique<SmallFish>(random_number));
        
        if (i > 4)
        {
            m_fish_eaten[i - 1]->setRotation();
            m_fish_eaten[i - 1]->setPosition(0, window.getSize().y * (i - 4.25));
        }
        else
            m_fish_eaten[i - 1]->setPosition(window.getSize().x, window.getSize().y * (i - 0.5));
    }
    m_fish_eaten.push_back(std::make_unique<ObstacleFish>());
    m_fish_eaten[m_fish_eaten.size() - 1]->setPosition(0, 0);

    m_player->setPosition(window.getSize().x, window.getSize().y);
    while (m_window->isOpen())
    {
        const auto deltaTime = m_game_clock.restart();
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||m_player->getGameOver())
                m_window->close();
        }
        m_player->move(deltaTime,*m_window,1);
        handleCollisions(*m_player);
        //m_player->animate(deltaTime);
        int i = 1;
        for (auto& it : m_fish_eaten)
        {
            if (i > 4)
                it->move(deltaTime, *m_window, 1);
            else
                it->move(deltaTime, *m_window, -1);
            handleCollisions(*it);
            i++;
        }
        m_text_score.setString("SCORE: " + std::to_string(m_player->getScore()));
        m_window->clear();
        m_window->draw(m_bec_level);
        for (auto& it: m_fish_eaten)
        {
            if(!it->getIsEaten())
                it->draw(*m_window);
        }
        m_player->draw(*m_window);
        m_window->draw(m_text_score);
        m_window->display();
    }
}
//-------------------------------------------------------
void Level1::handleCollisions(GameObject& gameObject)
{
    for (size_t i = 0; i < m_fish_eaten.size(); i++)
    {
        if (gameObject.checkCollision(*m_fish_eaten[i]))
        {
            gameObject.handleCollision(*m_fish_eaten[i]);
        }
    }

    for (size_t i = 0; i < m_fish_eaten.size(); i++)
    {
        if (gameObject.checkCollision(*m_fish_eaten[i]))
        {
            gameObject.handleCollision(*m_fish_eaten[i]);
        }
    }
    if (gameObject.checkCollision(*m_player))
    {
        gameObject.handleCollision(*m_player);
    }
}
