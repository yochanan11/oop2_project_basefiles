#include "Fish/Fish.h"

//--------------------------------
Fish::Fish(int score):m_score(score){
	//getSprite().setTexture(Resources::instance().getTexture(ObjIndex::BACKGROUND));
}
//--------------------------------
Fish::~Fish(){}
//--------------------------------
int Fish::getScore() const { return m_score; }
//--------------------------------
 void Fish::setScore(const int score)  {  m_score = score; }
//--------------------------------

