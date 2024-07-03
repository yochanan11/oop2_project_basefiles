#include "Fish/SmallFish.h"

//----------------------------------
SmallFish::SmallFish(const int rand) :FishEaten(2)
{
	m_sprite.setTexture(getRandTex(rand));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
		m_sprite.getGlobalBounds().height / 2.f);
}
//----------------------------------
SmallFish::~SmallFish()
{
}
//----------------------------------
sf::Texture& SmallFish::getRandTex(const int rand)
{
	switch (rand)
	{
	case 1:
		return Resources::instance().getTexture(ObjIndex::FISH_E1);
		break;
	case 2:
		return Resources::instance().getTexture(ObjIndex::FISH_E2);
		break;
	case 3:
		return Resources::instance().getTexture(ObjIndex::FISH_E3);
		break;
	case 4:
		return Resources::instance().getTexture(ObjIndex::FISH_E4);
		break;
	default:
		break;
	}
}