#include "Fish/Fish.h"

//--------------------------------
Fish::Fish(int score):m_score(score){
}
//--------------------------------
Fish::~Fish(){}
//--------------------------------
int Fish::getScore() const { return m_score; }
//--------------------------------
 void Fish::setScore(const int score)  {
	 if (score < 0)
		 m_score = 0;
	 m_score = score; 
 }
//--------------------------------

