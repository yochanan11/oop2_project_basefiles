#include "Menu/NewGame.h"

NewGame::NewGame():Command(Resources::instance().getTexture(ObjIndex::F_PLAYER),sf::Vector2f(0,0))
{
}

NewGame::~NewGame()
{
}

void NewGame::execute()
{
}