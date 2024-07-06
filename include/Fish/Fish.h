#pragma once
#include "GameObject.h"

class Fish:  virtual public GameObject
{
public:
	Fish(int);
	virtual ~Fish();
	int getScore()const;
	void setScore(const int);
	virtual void move(sf::Time) = 0;

protected:
	int m_score;
private:
	
};

