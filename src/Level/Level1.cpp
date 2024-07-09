#include "Level/Level1.h"
#include <iostream>
#include "Obstacle.h"
#include "GiftFreeze.h"
#include "GiftSpeed.h"

//---------------------------------
Level1::Level1(Player& player) : Level(player, Resources::instance().getTexture(ObjIndex::BACKGROUND))
, m_fish_counter(0)
{
    m_small_fish.setScale(0.45f, 0.45f);
    m_small_fish.setPosition(WINDOW_WIDHT - 100,20);
    m_medium_fish.setScale(0.35f, 0.35f);
    m_medium_fish.setPosition(WINDOW_WIDHT - 180, 20);
    m_text_score.setPosition(50,20);
}
//---------------------------------
Level1::~Level1() {}
//---------------------------------
void Level1::run() {
    
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDHT, WINDOW_HEIGHT), "Fish Eats Fish");
    m_window = &window;
    newGame();
    sf::Clock fishCreationClock; // Clock to track time for creating fish
    float nextFishCreationTime = static_cast<float>(std::rand() % 2000 + 400); // Random interval between 1 and 5 seconds (1000 to 5000 ms)

    sf::Clock obstacleCreationClock; // Clock to track time for creating obstacles
    float nextObstacleCreationTime = static_cast<float>(std::rand() % 29000 + 1000); // Random interval between 1 and 20 seconds (1000 to 20000 ms)

    while (m_window->isOpen()) {
        const auto deltaTime = m_game_clock.restart();
        try {


            

            // Check if the elapsed time has passed the random interval for creating obstacles
            if (obstacleCreationClock.getElapsedTime().asMilliseconds() >= nextObstacleCreationTime) {
                createFish(std::rand(), true); // Create an obstacle fish
                obstacleCreationClock.restart(); // Reset the clock
                nextObstacleCreationTime = static_cast<float>(std::rand() % 29000 + 1000); // New random interval (1 to 20 seconds)
            }

            // Check if the elapsed time has passed the random interval for creating fish
            if (fishCreationClock.getElapsedTime().asMilliseconds() >= nextFishCreationTime) {
                createFish(std::rand(), false); // Create a random fish
                fishCreationClock.restart(); // Reset the clock
                nextFishCreationTime = static_cast<float>(std::rand() % 2000 + 400); // New random interval (1 to 5 seconds)
            }

            m_player->move(deltaTime);
            m_player->setRotationAndScale();

            handleCollisions(*m_player);

            // Move fish and remove those that are eaten or off-screen
            for (auto& it : m_fish) {
                it->move(deltaTime);
            }
            m_fish.erase(std::remove_if(m_fish.begin(), m_fish.end(),
                [](const std::unique_ptr<Fish>& fish) {
                    return fish->getIsEaten();
                }),
                m_fish.end());

            m_objects.erase(std::remove_if(m_objects.begin(), m_objects.end(),
                [](const std::unique_ptr<IsEaten>& object) {
                    return object->getIsEaten();
                }),
                m_objects.end());

            m_text_score.setString(m_player->getName() + " your score: " + std::to_string(m_player->getScore()));
            sf::Event event;
            while (m_window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }
            
        }
        catch (const std::exception&)
        {
            gameOver();
        }
        m_window->clear();
        m_window->draw(m_bec_level);
        for (auto& it : m_fish) 
            it->draw(*m_window);
        for (auto& it : m_objects) 
            it->draw(*m_window);
        for(auto& it : m_obstacle)
            it->draw(*m_window);
        m_player->draw(*m_window);
        m_window->draw(m_top_rec);
        m_window->draw(m_text_score);
        m_window->draw(m_small_fish);
        if (m_player->getScore() >= 16)
            m_window->draw(m_medium_fish);
        m_window->display();
    }
}
//-------------------------------------------------------
void Level1::handleCollisions(GameObject& gameObject) {
    for (size_t i = 0; i < m_fish.size(); i++) {
        if (gameObject.checkCollision(*m_fish[i])) {
            gameObject.handleCollision(*m_fish[i]);
        }
    }
    for (size_t i = 0; i < m_objects.size(); i++) {
        if (gameObject.checkCollision(*m_objects[i])) {
            gameObject.handleCollision(*m_objects[i]);
        }
    }
    for (size_t i = 0; i < m_obstacle.size(); i++) {
        if (gameObject.checkCollision(*m_obstacle[i])) {
            gameObject.handleCollision(*m_obstacle[i]);
        }
    }
    if (gameObject.checkCollision(*m_player)) {
        gameObject.handleCollision(*m_player);
    }
}
//-------------------------------------------------------
void Level1::createFish(int rand, bool isObstacle) {
    auto random = std::rand();
    int numGift = 1;
    auto direction = rand % 2 == 0 ? 1 : -1;
    if (random % 2 == 0)
        direction *= -1;

    std::unique_ptr<Fish> fish;

    if (m_fish_counter < 10) {
        // Create small fish for the first 10 fish
        fish = std::make_unique<SmallFish>(rand % 4 + 1);
    }
    else {
        // After 10 fish, create a mix of fish types
        if (isObstacle) {
            fish = std::make_unique<ObstacleFish>();
        }
        else {
            auto randFish = rand % 2 + 1;
            if (randFish == 1) {
                fish = std::make_unique<SmallFish>(rand % 4 + 1);
            }
            else {
                fish = std::make_unique<MediumFish>();
            }
        }

        // Every 10 fish, create a gift
        if (m_fish_counter != 0 && m_fish_counter % (numGift * 10) == 0) {
            createGift();
            numGift++;
        }
    }
    fish->setDirection(direction);

    auto width = fish->getGlobalBounds().width;

    if (direction == -1) {
        fish->setPosition(m_window->getSize().x + width,
            rand % m_window->getSize().y);
    }
    else {
        fish->setRotation();
        fish->setPosition(-width, rand % m_window->getSize().y);
    }

    m_fish.push_back(std::move(fish));
    m_fish_counter++;
}
//-------------------------------------
void Level1::createObstacle() {
    for (size_t i = 0; i < 3; i++) {
        auto obstacle = std::make_unique<Obstacle>();
        obstacle->setPosition((i + 1) * 350.f, WINDOW_HEIGHT - 50.f);
        m_obstacle.push_back(std::move(obstacle));
    }
}
//-------------------------------------
void Level1::createGift()
{
   
        std::unique_ptr<Gift> gift;
        int randomGiftType = std::rand() % 2; // מספר המתנות השונות

        switch (randomGiftType) {
        case 0:
            gift = std::make_unique<GiftFreeze>();
            break;
        case 1:
            gift = std::make_unique<GiftSpeed>();
            break;
            // הוסף כאן מקרים נוספים עבור מתנות אחרות בעתיד
        }

        // Initialize the gift position
        gift->setPosition(std::rand() % WINDOW_WIDHT, std::rand() % WINDOW_HEIGHT);
        m_objects.push_back(std::move(gift)); // Add the gift to the list

}
//-------------------------------------
void Level1::gameOver() {
        Resources::instance().playSound(SoundIndex::GAME_OVER);
        m_window->draw(m_game_over_rec);
        m_window->draw(m_gameOverText);
        m_window->display();
        sf::sleep(sf::seconds(3));
        m_window->close();
}
//-------------------------------------
void Level1::newGame() {
    
    m_fish.clear();
    m_objects.clear();
    m_player->setScore(0);
    m_player->setGameOver(false);
    m_player->setFirstScale();
    m_player->setPosition(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2);
    
    std::srand(std::time(0));
    m_fish_counter = 0; // Reset fish counter
    createObstacle();
   
}

