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


private:

};

