#include "Menu/NewGame.h"
#include "Resources.h"

NewGame::NewGame(Controller* controller)
    : Command(Resources::instance().getTexture(ObjIndex::NEW_GAME_B), sf::Vector2f(200, 475)), m_controller(controller) // העברת המצביע
{
    m_sprite_menu.setScale(0.35f, 0.35f);
}
//------------------------------------
NewGame::~NewGame() {}
//------------------------------------
void NewGame::execute() {
    m_controller->runGame(); // קריאה לפונקציה להפעיל את המשחק
}
