#pragma once
#include "IsEaten.h"

class Fish:  virtual public IsEaten
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

