#include "GiftFreeze.h"

GiftFreeze::GiftFreeze()
{
	m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::GIFT));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
		m_sprite.getGlobalBounds().height / 2.f);
}
//---------------------------------------
GiftFreeze::~GiftFreeze()
{
}
//---------------------------------------
void GiftFreeze::handleCollision(GameObject& gameObject) { gameObject.handleCollision(*this); }
//---------------------------------------
void GiftFreeze::handleCollision(Player& gameObject)
{
	gameObject.handleCollision(*this);
}
//---------------------------------------
void GiftFreeze::handleCollision(FishEaten& gameObject){}
//---------------------------------------
void GiftFreeze::handleCollision(Obstacle& gameObject){}
//---------------------------------------
 void GiftFreeze::handleCollision(ObstacleFish& gameObject){}
//---------------------------------------
//void GiftFreeze::handleCollision(GiftFreeze& gameObject)
//{
//}
////---------------------------------------

