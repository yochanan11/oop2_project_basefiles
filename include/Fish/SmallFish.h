#pragma once
#include "Fish/FishEaten.h"

class SmallFish: public FishEaten
{
public:
	SmallFish(const int);
	~SmallFish();

private:
	sf::Texture& getRandTex(const int);
};

