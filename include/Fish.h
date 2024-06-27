#pragma once
#include "GameObject.h"

class Fish:  virtual public GameObject
{
public:
	Fish(int);
	~Fish();
	int getScore()const;
protected:
	int m_score;
private:
	
};

