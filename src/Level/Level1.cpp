#include "Level/Level1.h"
#include <iostream>

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
    m_fish_eaten.clear();
    m_player->setScore(0);
    sf::RenderWindow window(sf::VideoMode(1400, 900), "Fish Eats Fish");
    m_window = &window;
    m_text_score.setPosition(sf::Vector2f(50.f, 50.f));
    std::srand(std::time(0));

    m_fish_eaten.push_back(std::make_unique<ObstacleFish>());

    m_player->setPosition(window.getSize().x / 2, window.getSize().y / 2);
    sf::Clock fishCreationClock; // Clock to track time for creating fish
    float nextFishCreationTime = static_cast<float>(std::rand() % 2500 + 500); // Random interval between 1 and 5 seconds (1000 to 5000 ms)

    while (m_window->isOpen())
    {
        const auto deltaTime = m_game_clock.restart();
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || m_player->getGameOver())
                m_window->close();
        }

        // Check if the elapsed time has passed the random interval
        if (fishCreationClock.getElapsedTime().asMilliseconds() >= nextFishCreationTime)
        {
            createRandomFish(std::rand());
            fishCreationClock.restart(); // Reset the clock
            nextFishCreationTime = static_cast<float>(std::rand() % 2500 + 500); // New random interval
        }

        m_player->move(deltaTime, *m_window);
        m_player->setRotationAndScale();

        handleCollisions(*m_player);
        //m_player->animate(deltaTime);

        // Move fish and remove those that are eaten or off-screen
        for (auto& it : m_fish_eaten)
        {
            it->move(deltaTime, *m_window);
        }
        m_fish_eaten.erase(std::remove_if(m_fish_eaten.begin(), m_fish_eaten.end(),
            [](const std::unique_ptr<GameObject>& fish) {
                return fish->getIsEaten();
            }),
            m_fish_eaten.end());

        m_text_score.setString("SCORE: " + std::to_string(m_player->getScore()));
        m_window->clear();
        m_window->draw(m_bec_level);
        for (auto& it : m_fish_eaten)
        {
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

void Level1::createRandomFish(int rand)
{
    auto direction = rand % 2 == 0 ? 1 : -1;
    auto width = m_fish_eaten[m_fish_eaten.size() - 1]->getGlobalBounds().width;

    m_fish_eaten.push_back(std::make_unique<SmallFish>(rand % 4 + 1));
    m_fish_eaten[m_fish_eaten.size() - 1]->setDirection(direction);

    // Set a random scale between 0.3 and 1.8
    float scale = static_cast<float>(rand % 10 + 3) / 10.0f;
    m_fish_eaten[m_fish_eaten.size() - 1]->setScale(scale, scale);

    if (direction == -1)
    {
        m_fish_eaten[m_fish_eaten.size() - 1]->setPosition(m_window->getSize().x + width,
            rand % m_window->getSize().y);
    }
    else
    {
        m_fish_eaten[m_fish_eaten.size() - 1]->setRotation();
        m_fish_eaten[m_fish_eaten.size() - 1]->setPosition(-width, rand % m_window->getSize().y);
    }
}
