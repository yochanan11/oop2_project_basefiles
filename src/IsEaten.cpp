#include "IsEaten.h"


IsEaten::IsEaten(){}
//-----------------------------
IsEaten::~IsEaten(){}
//-----------------------------
bool IsEaten::getIsEaten() const { return m_eaten; }
//-----------------------------
void IsEaten::setIsEaten(bool eaten){m_eaten = eaten; }