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
    m_player->setGameOver(false);
    m_player->setFirstScale();
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDHT, WINDOW_HEIGHT), "Fish Eats Fish");
    m_window = &window;
    m_text_score.setPosition(sf::Vector2f(50.f, 50.f));
    std::srand(std::time(0));

    m_fish_eaten.push_back(std::make_unique<ObstacleFish>());

    sf::Clock fishCreationClock; // Clock to track time for creating fish
    float nextFishCreationTime = static_cast<float>(std::rand() % 2000 + 400); // Random interval between 1 and 5 seconds (1000 to 5000 ms)

    sf::Clock obstacleCreationClock; // Clock to track time for creating obstacles
    float nextObstacleCreationTime = static_cast<float>(std::rand() % 29000 + 1000); // Random interval between 1 and 20 seconds (1000 to 20000 ms)

    while (m_window->isOpen())
    {
        const auto deltaTime = m_game_clock.restart();
       
        if (m_player->getGameOver()) {
            Resources::instance().playSound(SoundIndex::GAME_OVER);
            // הצגת "Game Over" על המסך
            m_window->draw(m_game_over_rec);
            m_window->draw(m_gameOverText);
            m_window->display();
            sf::sleep(sf::seconds(3)); // המתנה של 3 שניות לפני סגירת המשחק
            m_window->close();
        }
        // Check if the elapsed time has passed the random interval for creating obstacles
        if (obstacleCreationClock.getElapsedTime().asMilliseconds() >= nextObstacleCreationTime)
        {
            createFish(std::rand(), true); // Create an obstacle fish
            obstacleCreationClock.restart(); // Reset the clock
            nextObstacleCreationTime = static_cast<float>(std::rand() % 29000 + 1000); // New random interval (1 to 20 seconds)
        }

        // Check if the elapsed time has passed the random interval for creating fish
        if (fishCreationClock.getElapsedTime().asMilliseconds() >= nextFishCreationTime)
        {
            createFish(std::rand(), false); // Create a random fish
            fishCreationClock.restart(); // Reset the clock
            nextFishCreationTime = static_cast<float>(std::rand() % 2000 + 400); // New random interval (1 to 5 seconds)
        }

        m_player->move(deltaTime);
        m_player->setRotationAndScale();

        handleCollisions(*m_player);

        // Move fish and remove those that are eaten or off-screen
        for (auto& it : m_fish_eaten)
        {
            it->move(deltaTime);
        }
        m_fish_eaten.erase(std::remove_if(m_fish_eaten.begin(), m_fish_eaten.end(),
            [](const std::unique_ptr<GameObject>& fish) {
                return fish->getIsEaten();
            }),
            m_fish_eaten.end());

        m_text_score.setString("SCORE: " + std::to_string(m_player->getScore()));
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();

        }
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
//-------------------------------------------------------
void Level1::createFish(int rand, bool isObstacle)
{
    auto random = std::rand();
    auto direction = rand % 2 == 0 ? 1 : -1;
    if (random % 2 == 0)
        direction *= -1;

    std::unique_ptr<GameObject> fish;
    if (isObstacle)
        fish = std::make_unique<ObstacleFish>();
    else
    {
        auto randFish = rand % 2 + 1;
        if(randFish == 1)
            fish = std::make_unique<SmallFish>(rand % 4 + 1);
        else
            fish = std::make_unique<MediumFish>();
       /* float scale = static_cast<float>(rand % 10 + 1 + m_player->getScore() / 10) / 10.0f;
        fish->setScale(scale, scale);*/
    }

    fish->setDirection(direction);

    auto width = fish->getGlobalBounds().width;

    if (direction == -1)
    {
        fish->setPosition(m_window->getSize().x + width,
            rand % m_window->getSize().y);
    }
    else
    {
        fish->setRotation();
        fish->setPosition(-width, rand % m_window->getSize().y);
    }

    m_fish_eaten.push_back(std::move(fish));
}
