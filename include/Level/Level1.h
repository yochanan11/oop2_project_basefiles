#pragma once
#include "Level.h"
#include "Player.h"

class Level1 : public Level
{
public:
    Level1();
    Level1(Player& player);
    ~Level1();

    void run() override;

private:
    void handleCollisions(GameObject& gameObject);
    void createFish(int rand, bool isObstacle);
    void createObstacle();
    void createGift();
    void gameOver();
    void newGame();

    int m_fish_counter;
};
