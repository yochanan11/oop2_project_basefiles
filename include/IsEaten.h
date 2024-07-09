#pragma once
#include "GameObject.h"

class IsEaten : virtual public GameObject
{
public:
	IsEaten();
	virtual ~IsEaten();
	void setIsEaten(bool);
	bool getIsEaten() const;
protected:
	bool m_eaten = false;
private:

};

