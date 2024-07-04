#include "Fish/MediumFish.h"

//----------------------------------
MediumFish::MediumFish() :FishEaten(5)
{
	m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::MEDIUM_FISH));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
		m_sprite.getGlobalBounds().height / 2.f);
}
//----------------------------------
MediumFish::~MediumFish()
{
}
//----------------------------------
