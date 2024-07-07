#pragma once
#include "Gift.h"
#include "Player.h"

class GiftSpeed : public Gift
{
public:
    GiftSpeed();
    ~GiftSpeed();
    virtual void handleCollision(GameObject& gameObject) override;
    virtual void handleCollision(Player& gameObject) override;
    virtual void handleCollision(FishEaten& gameObject) override;
    virtual void handleCollision(ObstacleFish& gameObject) override;
    virtual void handleCollision(Obstacle& gameObject) override;
    virtual void handleCollision(GiftFreeze& gameObject) override;
    virtual void handleCollision(GiftSpeed& gameObject) override;


private:
};
