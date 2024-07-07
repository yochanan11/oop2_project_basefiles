#include "GiftSpeed.h"

GiftSpeed::GiftSpeed()
{
    m_sprite.setTexture(Resources::instance().getTexture(ObjIndex::RED_GIFT));
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
        m_sprite.getGlobalBounds().height / 2.f);
    m_sprite.setScale(0.35f, 0.35f);
}
//---------------------------------------
GiftSpeed::~GiftSpeed()
{
}
//---------------------------------------
void GiftSpeed::handleCollision(GameObject& gameObject) { gameObject.handleCollision(*this); }
//---------------------------------------
void GiftSpeed::handleCollision(Player& gameObject)
{
    if (!m_eaten)
        gameObject.handleCollision(*this);
    m_eaten = true;
}
//---------------------------------------
void GiftSpeed::handleCollision(FishEaten& gameObject) {}
//---------------------------------------
void GiftSpeed::handleCollision(Obstacle& gameObject) {}
//---------------------------------------
void GiftSpeed::handleCollision(ObstacleFish& gameObject) {}
//---------------------------------------
void GiftSpeed::handleCollision(GiftFreeze& gameObject) {}
//---------------------------------------
void GiftSpeed::handleCollision(GiftSpeed& gameObject) {}
//---------------------------------------
