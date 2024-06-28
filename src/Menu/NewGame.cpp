#include "Menu/NewGame.h"

NewGame::NewGame():Command(Resources::instance().getTexture(ObjIndex::NEW_GAME_B)
	,sf::Vector2f(0,0))
{
}

NewGame::~NewGame()
{
}

void NewGame::execute()
{

}