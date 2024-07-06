#pragma once
#include "Level/Level.h"

class Level1:public Level
{
public:
	Level1();
	Level1(Player&);
	~Level1();
	void run() override;
	void handleCollisions(GameObject& );
	//void createRandomFish(int);

private:
	void createFish(int rand, bool isObstacle);
	void createObstacle();
	void createGift();
	void gameOver();
	void newGame();
	int m_fish_counter;

};

